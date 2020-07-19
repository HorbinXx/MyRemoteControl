#ifndef NETSERVER_H
#define NETSERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<qmath.h>
#include<commondata.h>
#include <heartthread.h>

class NetServer : public QObject
{
    Q_OBJECT
public:
    NetServer(int port=10086, int maxClient=10);

    bool send(int index, common::packetType type, char* data);
    void read();

    void beat(int index);
private:
    QTcpServer* tcpServer;
    QList<QTcpSocket*> tcpSockets;
    QList<bool> socketsBeatBuf;
    const int interval = 3000;
    int maxClient;

    QByteArray readBuf;
    QList<QByteArray> datasBuf;
    QList<int> numsBuf;

    HeartThread *heartThread;
private:
    void newConnection();
    void disConnected(QAbstractSocket::SocketState socketState);
    void socketsBeat();
signals:
    void newClient(QTcpSocket* socket);
    void disClient(int index);
    void readData(common::packetType type, int index, char* data);
};

#endif // NETSERVER_H
