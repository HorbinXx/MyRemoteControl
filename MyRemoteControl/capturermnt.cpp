#include "capturermnt.h"
#include "ui_capturermnt.h"

#include <QDebug>


CapturerMnt::CapturerMnt(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CapturerMnt)
{
    ui->setupUi(this);
    desktop=nullptr;
}

CapturerMnt::~CapturerMnt()
{
    delete ui;
}

void CapturerMnt::refresh(char* data)
{
    QByteArray ba = QByteArray::fromBase64(data);
    QPixmap pix;

    pix.loadFromData(ba);
    if(desktop==nullptr){
        this->desktop = new QGraphicsPixmapItem(pix);
        desktop->setTransformationMode(Qt::TransformationMode::SmoothTransformation);
        this->scene = new QGraphicsScene(this);
        scene->addItem(this->desktop);
        ui->graphicsView->setScene(scene);
        resizeEvent(nullptr);
    }else this->desktop->setPixmap(pix);
}

void CapturerMnt::resizeEvent(QResizeEvent *event)
{
    QMainWindow::resizeEvent(event) ;
    if( ui->graphicsView->rect().height()>100 && desktop != nullptr){//用来防止窗口大小使用默认值
        qreal radio1 = (qreal)ui->graphicsView->width()/(qreal)desktop->pixmap().width();
        qreal radio2 = (qreal)ui->graphicsView->height()/(qreal)desktop->pixmap().height();
        radio1<radio2 ? desktop->setScale(radio1) : desktop->setScale(radio2);
    }
}
