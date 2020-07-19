#ifndef CMDTHREAD_H
#define CMDTHREAD_H

#include<QThread>
#include<QObject>
#include <QTextCodec>
#include "commondata.h"
#include "windows.h"
#include "mythread.h"

class CMDThread : public MyThread
{
    Q_OBJECT
public:
    CMDThread();
    void exctCMD(char* data);

protected:
    virtual void run();
private:
    HANDLE hMyWritePipe;
};

#endif // CMDTHREAD_H
