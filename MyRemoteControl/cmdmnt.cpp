#include "cmdmnt.h"
#include "ui_cmdmnt.h"

CMDMnt::CMDMnt(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CMDMnt)
{
    ui->setupUi(this);
    index = -1;
}

CMDMnt::~CMDMnt()
{
    delete ui;
}

void CMDMnt::appentText(char* text)
{
    ui->CMDEdit->append(text);
}

void CMDMnt::setIndex(int index)
{
    this->index = index;
}

int CMDMnt::getIndex()
{
    return index;
}

void CMDMnt::on_exctButton_clicked()
{
    if(index<0)return;//TODO
    QByteArray ba=ui->CMDLine->text().toLatin1();
    char *data=ba.data();
    emit exctCMD(data);
}
