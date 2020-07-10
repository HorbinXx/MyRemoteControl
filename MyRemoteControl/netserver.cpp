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
    int len = strlen(data);
    if(len > DATA_MAX_LEN)return false;//数据超出大小
    common::UPacket* packet = new common::UPacket();
    packet->type = type;
    packet->length = ++len;
    memcpy(packet->data,data, packet->length);

    QTcpSocket* socekt = tcpSockets[index];
    int num = socekt->write((const char*)packet, len+PACKET_HEAD_LEN);
    return num>0;
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
        QByteArray tmpBuf = readBuf;
        memcpy(&type, tmpBuf, sizeof (short));
        tmpBuf.remove(0, sizeof (short));
        memcpy(&len, tmpBuf, sizeof (short));
        tmpBuf.remove(0, sizeof (short));

        if(total_length < (int)(len+PACKET_HEAD_LEN))break;//不够数据长度
        char data[256] = { 0 };
        memcpy(data, tmpBuf, len);
        tmpBuf.remove(0, len);

        common::UPacket* packet = new common::UPacket();
        packet->type = type;
        packet->length = len;
        memcpy(packet->data,data, packet->length);
        emit readData(packet);
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
