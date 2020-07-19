#include "heartthread.h"
#include<QDebug>

HeartThread::HeartThread(int interval)
{
    this->interval = interval;
}

void HeartThread::run()
{
    while(!isStop){
        Sleep(interval);
        if(!isStop)emit beat();
    }
}
