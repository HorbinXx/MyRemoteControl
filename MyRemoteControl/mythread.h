#ifndef MYTHREAD_H
#define MYTHREAD_H

#include<QThread>

class MyThread : public QThread
{
    Q_OBJECT
public:
    MyThread();
    void closeThread();
    void startThread();

protected:
    volatile bool isStop;

signals:
    void client_send_data(int type,QByteArray data);
};

#endif // MYTHREAD_H
