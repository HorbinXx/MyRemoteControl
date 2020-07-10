#ifndef KEYBOARDMNT_H
#define KEYBOARDMNT_H

#include <QWidget>

namespace Ui {
class KeyBoardMnt;
}

class KeyBoardMnt : public QWidget
{
    Q_OBJECT

public:
    explicit KeyBoardMnt(QWidget *parent = nullptr);
    ~KeyBoardMnt();

    void appentText(QString text);

private slots:
    void on_pushButton_clicked();

private:
    Ui::KeyBoardMnt *ui;
};

#endif // KEYBOARDMNT_H
