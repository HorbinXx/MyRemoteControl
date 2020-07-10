#include "keyboardmnt.h"
#include "ui_keyboardmnt.h"

KeyBoardMnt::KeyBoardMnt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::KeyBoardMnt)
{
    ui->setupUi(this);
}

KeyBoardMnt::~KeyBoardMnt()
{
    delete ui;
}

void KeyBoardMnt::appentText(QString text)
{
    ui->textEdit->append(text);
}

void KeyBoardMnt::on_pushButton_clicked()
{
    ui->textEdit->clear();
}
