/********************************************************************************
** Form generated from reading UI file 'keyboardmnt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDMNT_H
#define UI_KEYBOARDMNT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_KeyBoardMnt
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QTextEdit *textEdit;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QWidget *KeyBoardMnt)
    {
        if (KeyBoardMnt->objectName().isEmpty())
            KeyBoardMnt->setObjectName(QString::fromUtf8("KeyBoardMnt"));
        KeyBoardMnt->resize(400, 547);
        verticalLayout_2 = new QVBoxLayout(KeyBoardMnt);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        textEdit = new QTextEdit(KeyBoardMnt);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        textEdit->setReadOnly(true);

        verticalLayout->addWidget(textEdit);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(KeyBoardMnt);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(KeyBoardMnt);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setEnabled(false);
        pushButton_2->setFocusPolicy(Qt::StrongFocus);
        pushButton_2->setToolTipDuration(-1);

        horizontalLayout->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(KeyBoardMnt);

        QMetaObject::connectSlotsByName(KeyBoardMnt);
    } // setupUi

    void retranslateUi(QWidget *KeyBoardMnt)
    {
        KeyBoardMnt->setWindowTitle(QCoreApplication::translate("KeyBoardMnt", "\351\224\256\347\233\230\347\233\221\346\216\247", nullptr));
        pushButton->setText(QCoreApplication::translate("KeyBoardMnt", "\346\270\205\345\261\217", nullptr));
        pushButton_2->setText(QCoreApplication::translate("KeyBoardMnt", "\345\257\274\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class KeyBoardMnt: public Ui_KeyBoardMnt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDMNT_H
