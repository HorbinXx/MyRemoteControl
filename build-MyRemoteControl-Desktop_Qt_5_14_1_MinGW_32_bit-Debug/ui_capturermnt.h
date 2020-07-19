/********************************************************************************
** Form generated from reading UI file 'capturermnt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAPTURERMNT_H
#define UI_CAPTURERMNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CapturerMnt
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QGraphicsView *graphicsView;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CapturerMnt)
    {
        if (CapturerMnt->objectName().isEmpty())
            CapturerMnt->setObjectName(QString::fromUtf8("CapturerMnt"));
        CapturerMnt->resize(855, 518);
        centralwidget = new QWidget(CapturerMnt);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        graphicsView->setTransformationAnchor(QGraphicsView::NoAnchor);
        graphicsView->setResizeAnchor(QGraphicsView::NoAnchor);

        verticalLayout->addWidget(graphicsView);

        CapturerMnt->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CapturerMnt);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 855, 26));
        CapturerMnt->setMenuBar(menubar);
        statusbar = new QStatusBar(CapturerMnt);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        CapturerMnt->setStatusBar(statusbar);

        retranslateUi(CapturerMnt);

        QMetaObject::connectSlotsByName(CapturerMnt);
    } // setupUi

    void retranslateUi(QMainWindow *CapturerMnt)
    {
        CapturerMnt->setWindowTitle(QCoreApplication::translate("CapturerMnt", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CapturerMnt: public Ui_CapturerMnt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAPTURERMNT_H
