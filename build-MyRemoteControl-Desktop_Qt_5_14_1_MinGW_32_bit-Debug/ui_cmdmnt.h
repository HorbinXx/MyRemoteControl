/********************************************************************************
** Form generated from reading UI file 'cmdmnt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CMDMNT_H
#define UI_CMDMNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CMDMnt
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *CMDEdit;
    QHBoxLayout *horizontalLayout;
    QLineEdit *CMDLine;
    QPushButton *exctButton;

    void setupUi(QWidget *CMDMnt)
    {
        if (CMDMnt->objectName().isEmpty())
            CMDMnt->setObjectName(QString::fromUtf8("CMDMnt"));
        CMDMnt->resize(550, 565);
        verticalLayout = new QVBoxLayout(CMDMnt);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        CMDEdit = new QTextEdit(CMDMnt);
        CMDEdit->setObjectName(QString::fromUtf8("CMDEdit"));
        CMDEdit->setTextInteractionFlags(Qt::TextSelectableByMouse);

        verticalLayout->addWidget(CMDEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        CMDLine = new QLineEdit(CMDMnt);
        CMDLine->setObjectName(QString::fromUtf8("CMDLine"));

        horizontalLayout->addWidget(CMDLine);

        exctButton = new QPushButton(CMDMnt);
        exctButton->setObjectName(QString::fromUtf8("exctButton"));

        horizontalLayout->addWidget(exctButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(CMDMnt);

        QMetaObject::connectSlotsByName(CMDMnt);
    } // setupUi

    void retranslateUi(QWidget *CMDMnt)
    {
        CMDMnt->setWindowTitle(QCoreApplication::translate("CMDMnt", "CMD\346\216\247\345\210\266\347\253\257", nullptr));
        exctButton->setText(QCoreApplication::translate("CMDMnt", "\346\211\247\350\241\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CMDMnt: public Ui_CMDMnt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CMDMNT_H
