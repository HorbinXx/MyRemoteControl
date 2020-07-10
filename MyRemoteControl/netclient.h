#ifndef NETCLIENT_H
#define NETCLIENT_H

#include<QTcpSocket>
#include<QHostAddress>

#include<commondata.h>

class NetClient : public QObject
{
    Q_OBJECT
public:
    NetClient(QString serverIP="127.0.0.1", int serverPort=10086);
    void close();

    bool send(common::packetType type, char* data);
    void read();
private:
    QTcpSocket* tcpSocket;
    QByteArray readBuf;
signals:
    void readData(common::UPacket* paket);
};

#endif // NETCLIENT_H
