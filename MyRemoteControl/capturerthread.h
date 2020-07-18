#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include<QThread>
#include<QObject>
#include <QScreen>
#include <QGuiApplication>
#include <QPixmap>
#include <QBuffer>
#include "commondata.h"
#include <windows.h>

class CapturerThread : public QThread
{
    Q_OBJECT
public:
    CapturerThread();
    void closeThread();
    void startThread();

protected:
    virtual void run();
private:
    volatile bool isStop;
signals:
    void client_send_data(int type,QByteArray data);
};

#endif // CAPTURETHREAD_H
