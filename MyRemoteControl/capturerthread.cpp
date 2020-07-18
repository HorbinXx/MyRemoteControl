#include "capturerthread.h"
#include <QDebug>

CapturerThread::CapturerThread()
{
    isStop = false;
    this->start();
}

void CapturerThread::closeThread()
{
    isStop = true;
}

void CapturerThread::startThread()
{
    isStop = false;
    this->start();
}

void CapturerThread::run()
{
    while (true) {
        QScreen* screen = QGuiApplication::primaryScreen();
        QPixmap desktopImg = screen->grabWindow(0);
        QByteArray byteArray = QByteArray();
        QBuffer buffer(&byteArray);
        buffer.open(QIODevice::WriteOnly);
        desktopImg.save(&buffer,"jpeg",60);
        emit client_send_data((int)common::packetType::capture, byteArray);
        Sleep(100);
    }
}
