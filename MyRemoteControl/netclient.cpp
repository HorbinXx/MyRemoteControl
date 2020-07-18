#include "netclient.h"

NetClient::NetClient(QString serverIP, int serverPort)
{
    tcpSocket = new QTcpSocket(this);
    tcpSocket->connectToHost(QHostAddress(serverIP), serverPort);
    connect(tcpSocket, &QTcpSocket::readyRead, this, &NetClient::read);
}

void NetClient::close()
{
    tcpSocket->close();
}

bool NetClient::send(common::packetType type, char* data)
{
    int len = strlen(data);
    if(len > DATA_MAX_LEN){
        int tNum = qCeil(len/(float)DATA_MAX_LEN);
        for(int i=1; i<=tNum; i++){
            common::UPacket* packet = new common::UPacket();
            packet->type = type;
            if(i == tNum)packet->length = len % DATA_MAX_LEN;
            else packet->length = DATA_MAX_LEN;
            packet->tNum = tNum;
            packet->nNum = i;
            memcpy(packet->data, data+(i-1)*DATA_MAX_LEN, packet->length);
            tcpSocket->write((const char*)packet, packet->length+PACKET_HEAD_LEN);
        }
    }else{
        common::UPacket* packet = new common::UPacket();
        packet->type = type;
        packet->length = ++len;
        packet->tNum = 0;
        packet->nNum = 0;
        memcpy(packet->data,data, packet->length);
        tcpSocket->write((const char*)packet, len+PACKET_HEAD_LEN);
    }
    delete data;
    data = nullptr;
    return true;
}

void NetClient::read()
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
