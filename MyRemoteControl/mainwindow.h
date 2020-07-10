#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QList>
#include <QMessageBox>
#include <QLibrary>

#include <windows.h>
#include <thread>

#include <netserver.h>
#include <netclient.h>
#include <keyboardmnt.h>
#include <cmdmnt.h>
#include <cmdthread.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_CMDButton_clicked();
    void on_hookButton_clicked();
    void on_startServer_clicked();

    void on_newClient(QTcpSocket* socket);
    void on_disClient(int index);

    void on_clientConnect_clicked();

    void on_exctCMD(char* data);
    void on_client_send_data(int, QString);

private:
    NetServer* netServer;
    NetClient* netClient;
    KeyBoardMnt* keyBoardMnt;
    CMDMnt* cmdMnt;
    CMDThread* cmdThread;


    QLibrary* hookLib;

    void dispatchClientData(common::UPacket* packet);
    void dispatchServerData(common::UPacket* packet);

    void client_CMD(bool on_off);
    void client_KeyHook(bool on_off);
protected:
    bool nativeEvent(const QByteArray &eventType, void *message, long *result);
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
