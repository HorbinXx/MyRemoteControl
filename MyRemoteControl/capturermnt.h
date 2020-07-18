#ifndef CAPTURERMNT_H
#define CAPTURERMNT_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QTransform>
#include <QScreen>

namespace Ui {
class CapturerMnt;
}

class CapturerMnt : public QMainWindow
{
    Q_OBJECT

public:
    explicit CapturerMnt(QWidget *parent = nullptr);
    ~CapturerMnt();

    void refresh(char* data);

private:
    Ui::CapturerMnt *ui;
    QGraphicsScene* scene;
    QGraphicsPixmapItem* desktop;

private:
    virtual void resizeEvent(QResizeEvent * event);
};

#endif // CAPTURERMNT_H
