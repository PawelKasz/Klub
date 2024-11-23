#include "dialog.h"
#include "plat.h"
#include "ui_dialog_1.h"
#include "QGraphicsView"
#include <QGraphicsItem>
//#include <QDebug>

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , uii(new Ui::Dialog)
{
    uii->setupUi(this);

    scene = new QGraphicsScene (this);
    uii->graphicsView->setScene(scene);

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);
    QPen greenPen(Qt::green);
    blackPen.setWidth(3);
    greenPen.setWidth(5);


    ellipse = scene->addEllipse(-10,-10,300,100,blackPen,redBrush);
    ellipse1 = scene->addEllipse(50,50,100,100,blackPen,greenBrush);
    rectangle = scene->addRect(-75,-75,50,50);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    line = scene->addLine(-50,-50,200,-50,blackPen);
    line = scene->addLine(200,-50,240,-50,greenPen);

}

Dialog::~Dialog()
{
    delete uii;
}

void Dialog::on_pushButton_clicked()
{
    uii->graphicsView->rotate(-2);
    //ellipse->setRotation(2);
    ellipse->rotation();
    //ellipse->setRotation(90);
}

void Dialog::on_pushButton_2_clicked()
{
    uii->graphicsView->rotate(+2);
}

void Dialog::on_horizontalSlider_valueChanged(int value)
{
    int wartosc = value;
}

void Dialog::on_horizontalSlider_2_pressed(int value)
{
    qDebug() << "Okkk";
    Dialog::dane = value;
    uii->horizontalSlider->sliderMoved(30);

}

