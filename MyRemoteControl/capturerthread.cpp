#include "capturerthread.h"
#include <QDebug>

CapturerThread::CapturerThread()
{

}

void CapturerThread::run()
{
    while (!isStop) {
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
