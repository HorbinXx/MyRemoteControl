#ifndef CAPTURETHREAD_H
#define CAPTURETHREAD_H

#include <QScreen>
#include <QGuiApplication>
#include <QPixmap>
#include <QBuffer>
#include "commondata.h"
#include "mythread.h"
#include <windows.h>

class CapturerThread : public MyThread
{
public:
    CapturerThread();
protected:
    virtual void run();
};

#endif // CAPTURETHREAD_H
