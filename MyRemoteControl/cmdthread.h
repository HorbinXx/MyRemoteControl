#ifndef CMDTHREAD_H
#define CMDTHREAD_H

#include<QThread>
#include<QObject>
#include <QTextCodec>
#include "commondata.h"
#include"windows.h"

class CMDThread : public QThread
{
    Q_OBJECT
public:
    CMDThread(QObject *parent = 0);
    void closeThread();
    void startThread();

    void exctCMD(char* data);

protected:
    virtual void run();
private:
    volatile bool isStop;

    HANDLE hMyWritePipe;
signals:
    void client_send_data(int type,QByteArray data);
};

#endif // CMDTHREAD_H
