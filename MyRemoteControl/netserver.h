#ifndef NETSERVER_H
#define NETSERVER_H

#include<QTcpServer>
#include<QTcpSocket>
#include<qmath.h>
#include<commondata.h>

class NetServer : public QObject
{
    Q_OBJECT
public:
    NetServer(int port=10086, int interval=3000, int maxClient=10);

    bool send(int index, common::packetType type, char* data);
    void read();
private:
    QTcpServer* tcpServer;
    QList<QTcpSocket*> tcpSockets;
    int interval;
    int maxClient;

    QByteArray readBuf;
    QList<QByteArray> datasBuf;
    QList<int> numsBuf;
private:
    void newConnection();
    void disConnected(QAbstractSocket::SocketState socketState);

signals:
    void newClient(QTcpSocket* socket);
    void disClient(int index);
    void readData(common::packetType type, char* data);
};

#endif // NETSERVER_H
