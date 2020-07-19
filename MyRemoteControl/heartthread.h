#ifndef HEARTTHREAD_H
#define HEARTTHREAD_H

#include <QObject>
#include <QThread>
#include <windows.h>
#include "mythread.h"

class HeartThread : public MyThread
{
    Q_OBJECT
public:
    HeartThread(int interval);

protected:
    virtual void run();
private:
    int interval = 3000;
signals:
    void beat();
};

#endif // HEARTTHREAD_H
