#include "mythread.h"

MyThread::MyThread()
{
    isStop = false;
    this->start();
}

void MyThread::closeThread()
{
    isStop = true;
}

void MyThread::startThread()
{
    isStop = false;
    this->start();
}
