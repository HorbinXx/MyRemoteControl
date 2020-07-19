/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QListWidget *listWidget;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QGroupBox *groupBox_3;
    QPushButton *startServer;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_3;
    QLineEdit *serverPort;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_4;
    QLineEdit *serverMaxClient;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_5;
    QLineEdit *serverInterval;
    QGroupBox *groupBox_2;
    QPushButton *CMDButton;
    QPushButton *hookButton;
    QPushButton *capturerButton;
    QPushButton *hookButton_3;
    QPushButton *hookButton_4;
    QPushButton *hookButton_5;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox_4;
    QPushButton *clientConnect;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *connectIP;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_2;
    QLineEdit *connectPort;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        horizontalLayout_2 = new QHBoxLayout(centralwidget);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        horizontalLayout = new QHBoxLayout(tab);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMinimumSize(QSize(300, 0));
        groupBox->setMaximumSize(QSize(300, 16777215));
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        listWidget = new QListWidget(groupBox);
        listWidget->setObjectName(QString::fromUtf8("listWidget"));

        verticalLayout->addWidget(listWidget);


        horizontalLayout->addWidget(groupBox);

        widget = new QWidget(tab);
        widget->setObjectName(QString::fromUtf8("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        groupBox_3 = new QGroupBox(widget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        startServer = new QPushButton(groupBox_3);
        startServer->setObjectName(QString::fromUtf8("startServer"));
        startServer->setGeometry(QRect(330, 170, 93, 41));
        layoutWidget = new QWidget(groupBox_3);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(20, 30, 286, 83));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_3 = new QLabel(layoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_6->addWidget(label_3);

        serverPort = new QLineEdit(layoutWidget);
        serverPort->setObjectName(QString::fromUtf8("serverPort"));
        serverPort->setFrame(true);

        horizontalLayout_6->addWidget(serverPort);


        verticalLayout_4->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_4 = new QLabel(layoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_7->addWidget(label_4);

        serverMaxClient = new QLineEdit(layoutWidget);
        serverMaxClient->setObjectName(QString::fromUtf8("serverMaxClient"));
        serverMaxClient->setFrame(true);

        horizontalLayout_7->addWidget(serverMaxClient);


        verticalLayout_4->addLayout(horizontalLayout_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_5 = new QLabel(layoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_8->addWidget(label_5);

        serverInterval = new QLineEdit(layoutWidget);
        serverInterval->setObjectName(QString::fromUtf8("serverInterval"));
        serverInterval->setFrame(true);

        horizontalLayout_8->addWidget(serverInterval);


        verticalLayout_4->addLayout(horizontalLayout_8);


        verticalLayout_2->addWidget(groupBox_3);

        groupBox_2 = new QGroupBox(widget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        CMDButton = new QPushButton(groupBox_2);
        CMDButton->setObjectName(QString::fromUtf8("CMDButton"));
        CMDButton->setGeometry(QRect(20, 30, 93, 28));
        hookButton = new QPushButton(groupBox_2);
        hookButton->setObjectName(QString::fromUtf8("hookButton"));
        hookButton->setGeometry(QRect(120, 30, 93, 28));
        capturerButton = new QPushButton(groupBox_2);
        capturerButton->setObjectName(QString::fromUtf8("capturerButton"));
        capturerButton->setEnabled(true);
        capturerButton->setGeometry(QRect(320, 30, 93, 28));
        hookButton_3 = new QPushButton(groupBox_2);
        hookButton_3->setObjectName(QString::fromUtf8("hookButton_3"));
        hookButton_3->setEnabled(false);
        hookButton_3->setGeometry(QRect(220, 30, 93, 28));
        hookButton_4 = new QPushButton(groupBox_2);
        hookButton_4->setObjectName(QString::fromUtf8("hookButton_4"));
        hookButton_4->setEnabled(false);
        hookButton_4->setGeometry(QRect(20, 70, 93, 28));
        hookButton_5 = new QPushButton(groupBox_2);
        hookButton_5->setObjectName(QString::fromUtf8("hookButton_5"));
        hookButton_5->setEnabled(false);
        hookButton_5->setGeometry(QRect(120, 70, 93, 28));

        verticalLayout_2->addWidget(groupBox_2);


        horizontalLayout->addWidget(widget);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        horizontalLayout_3 = new QHBoxLayout(tab_2);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        groupBox_4 = new QGroupBox(tab_2);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        clientConnect = new QPushButton(groupBox_4);
        clientConnect->setObjectName(QString::fromUtf8("clientConnect"));
        clientConnect->setGeometry(QRect(320, 40, 93, 51));
        clientConnect->setToolTipDuration(-1);
        layoutWidget1 = new QWidget(groupBox_4);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(40, 40, 271, 54));
        verticalLayout_3 = new QVBoxLayout(layoutWidget1);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(layoutWidget1);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        connectIP = new QLineEdit(layoutWidget1);
        connectIP->setObjectName(QString::fromUtf8("connectIP"));
        connectIP->setFrame(true);

        horizontalLayout_4->addWidget(connectIP);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_2 = new QLabel(layoutWidget1);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_5->addWidget(label_2);

        connectPort = new QLineEdit(layoutWidget1);
        connectPort->setObjectName(QString::fromUtf8("connectPort"));
        connectPort->setFrame(true);

        horizontalLayout_5->addWidget(connectPort);


        verticalLayout_3->addLayout(horizontalLayout_5);


        horizontalLayout_3->addWidget(groupBox_4);

        tabWidget->addTab(tab_2, QString());

        horizontalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\347\256\200\346\230\223\350\277\234\347\250\213\346\216\247\345\210\266", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245\345\210\227\350\241\250", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257\350\256\276\347\275\256", nullptr));
        startServer->setText(QCoreApplication::translate("MainWindow", "\345\220\257\345\212\250\346\234\215\345\212\241\347\253\257", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257\347\253\257\345\217\243\357\274\232", nullptr));
        serverPort->setText(QCoreApplication::translate("MainWindow", "10086", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\350\277\236\346\216\245\346\225\260\357\274\232", nullptr));
        serverMaxClient->setText(QCoreApplication::translate("MainWindow", "10", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\345\277\203\350\267\263\351\227\264\351\232\224(ms)\357\274\232", nullptr));
        serverInterval->setText(QCoreApplication::translate("MainWindow", "3000", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\351\235\242\346\235\277", nullptr));
        CMDButton->setText(QCoreApplication::translate("MainWindow", "CMD\346\216\247\345\210\266", nullptr));
        hookButton->setText(QCoreApplication::translate("MainWindow", "\351\224\256\347\233\230\347\233\221\346\216\247", nullptr));
        capturerButton->setText(QCoreApplication::translate("MainWindow", "\345\261\217\345\271\225\347\233\221\346\216\247", nullptr));
        hookButton_3->setText(QCoreApplication::translate("MainWindow", "\346\221\204\345\203\217\345\244\264\347\233\221\346\216\247", nullptr));
        hookButton_4->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\266\210\346\201\257", nullptr));
        hookButton_5->setText(QCoreApplication::translate("MainWindow", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257\350\256\276\347\275\256", nullptr));
        clientConnect->setText(QCoreApplication::translate("MainWindow", "\350\277\236\346\216\245", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257IP\345\234\260\345\235\200\357\274\232", nullptr));
        connectIP->setText(QCoreApplication::translate("MainWindow", "127.0.0.1", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\346\234\215\345\212\241\347\253\257\347\253\257\345\217\243\357\274\232", nullptr));
        connectPort->setText(QCoreApplication::translate("MainWindow", "10086", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "\345\256\242\346\210\267\347\253\257", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
