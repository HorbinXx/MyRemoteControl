#ifndef CMDMNT_H
#define CMDMNT_H

#include <QWidget>
#include "netserver.h"

namespace Ui {
class CMDMnt;
}

class CMDMnt : public QWidget
{
    Q_OBJECT

public:
    explicit CMDMnt(QWidget *parent = nullptr);
    ~CMDMnt();

    void appentText(char* text);
    void setIndex(int index);
    int getIndex();

private slots:
    void on_exctButton_clicked();

private:
    Ui::CMDMnt *ui;
    int index;

signals:
    void exctCMD(char* data);
};

#endif // CMDMNT_H
