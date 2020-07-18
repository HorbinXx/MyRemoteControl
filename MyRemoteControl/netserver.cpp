#include "netserver.h"
#include<QDebug>
NetServer::NetServer(int port, int interval, int maxClient)
{
    tcpServer = new QTcpServer(this);
    tcpServer->listen(QHostAddress::Any, port);
    connect(tcpServer, &QTcpServer::newConnection, this, &NetServer::newConnection);

    this->interval = interval;
    this->maxClient = maxClient;
}

bool NetServer::send(int index, common::packetType type, char* data)
{
    int len = strlen(data);//获取数据长度
    if(len > DATA_MAX_LEN){
        //若一个包装不下，考虑分包
        int tNum = qCeil(len/(float)DATA_MAX_LEN);//分包个数
        for(int i=1; i<=tNum; i++){
            //逐个发包
            common::UPacket* packet = new common::UPacket();
            packet->type = type;
            if(i == tNum)packet->length = len % DATA_MAX_LEN;
            else packet->length = DATA_MAX_LEN;
            packet->tNum = tNum;
            packet->nNum = i;
            memcpy(packet->data, data+(i-1)*DATA_MAX_LEN, packet->length);
            QTcpSocket* socekt = tcpSockets[index];
            socekt->write((const char*)packet, len+PACKET_HEAD_LEN);
        }
    }else{
        //若一个包装得下，直接发包
        common::UPacket* packet = new common::UPacket();
        packet->type = type;
        packet->length = ++len;
        packet->tNum = 0;
        packet->nNum = 0;
        memcpy(packet->data,data, packet->length);
        QTcpSocket* socekt = tcpSockets[index];
        socekt->write((const char*)packet, len+PACKET_HEAD_LEN);
    }
    delete data;
    data = nullptr;
    return true;
}

void NetServer::read()
{
    QTcpSocket* socket = (QTcpSocket*)sender();
    QByteArray tmpBuf = socket->readAll();
    readBuf.append(tmpBuf);
    int total_length = readBuf.size();
    while(total_length > (int)PACKET_HEAD_LEN){
        unsigned short type;
        unsigned short len;
        unsigned int tNum;
        unsigned int nNum;
        QByteArray tmpBuf = readBuf;
        memcpy(&type, tmpBuf, sizeof (short));
        tmpBuf.remove(0, sizeof (short));
        memcpy(&len, tmpBuf, sizeof (short));
        tmpBuf.remove(0, sizeof (short));
        if(total_length < (int)(len+PACKET_HEAD_LEN))break;//不够数据长度
        memcpy(&tNum, tmpBuf, sizeof (int));
        tmpBuf.remove(0, sizeof (int));
        memcpy(&nNum, tmpBuf, sizeof (int));
        tmpBuf.remove(0, sizeof (int));
        if(tNum > 0){
            char dataChar[256] = { 0 };
            memcpy(dataChar, tmpBuf, len);
            QByteArray oneData(dataChar, len);
            datasBuf.append(oneData);
            numsBuf.append(nNum);
            tmpBuf.remove(0, len);
            if((int)tNum == numsBuf.length()){
                QByteArray data;
                for(int i=0; i<(int)tNum; i++){
                    int index = numsBuf.indexOf(i+1);
                    data.append(datasBuf[index]);
                    datasBuf.removeAt(index);
                    numsBuf.removeAt(index);
                }
                int len = data.length();
                char *charData = new char[len+1];
                memcpy(charData, data, len);
                charData[len] = 0;
                emit readData((common::packetType)type, charData);
            }
        }else{
            char *data = new char[len+1];
            memcpy(data, tmpBuf, len);
            tmpBuf.remove(0, len);
            data[len] = 0;
            emit readData((common::packetType)type, data);
        }
        readBuf = tmpBuf;//更新缓存
        total_length = readBuf.size();//更新长度
    }
}

void NetServer::newConnection()
{
    QTcpSocket* tcpSocket = tcpServer->nextPendingConnection();
    connect(tcpSocket, &QTcpSocket::stateChanged, this, &NetServer::disConnected);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &NetServer::read);

    tcpSockets.append(tcpSocket);
    emit newClient(tcpSocket);
}

void NetServer::disConnected(QAbstractSocket::SocketState socketState)
{
    if(socketState == QAbstractSocket::SocketState::UnconnectedState){
        QTcpSocket* tcpSocket = dynamic_cast<QTcpSocket*>(sender());
        int index = tcpSockets.indexOf(tcpSocket);
        tcpSockets.removeAt(index);
        emit disClient(index);
    }
}
