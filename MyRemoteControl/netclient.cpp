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
    if(len > DATA_MAX_LEN)return false;//数据超出大小
    common::UPacket* packet = new common::UPacket();
    packet->type = type;
    packet->length = ++len;
    memcpy(packet->data,data, packet->length);

    QTcpSocket* socket = tcpSocket;
    int num = socket->write((const char*)packet, len+PACKET_HEAD_LEN);
    return num>0;
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
