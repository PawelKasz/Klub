#include "dialog.h"
//#include "plat.h"
#include "skrzydlo.h"
#include "ui_dialog_1.h"
#include "QGraphicsView"
#include <QGraphicsItem>
#include <QDebug>


Dialog::Dialog(skrzydlo *p, QWidget *parent)
    : QDialog(parent)
    , uii(new Ui::Dialog)
{
    uii->setupUi(this);

    scene = new QGraphicsScene (this);
    uii->graphicsView->setScene(scene);

    scene->setSceneRect(-100, -100, 200, 200);  //To ustawia scene

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);
    QPen greenPen(Qt::green);
    blackPen.setWidth(3);
    greenPen.setWidth(5);


    ellipse = scene->addEllipse(0, 0,300,100,blackPen,redBrush);
    ellipse1 = scene->addEllipse(0,0,100,100,blackPen,greenBrush);
    rectangle = scene->addRect(-120,-50,5,5);
    rectangle = scene->addRect(130,0,5,5);

    rectangle = scene->addRect(-170,-50,5,5);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    rectangle = scene->addRect(50,150,5,5);
    rectangle->setFlag(QGraphicsItem::ItemIsMovable);


    NarysujLinie(blackPen, p);

    line = scene->addLine(-50,-50,200,-50,blackPen);
    line = scene->addLine(200,-50,240,-50,greenPen);
    line = scene->addLine(200,-40,238,-40,greenPen);
    //line = scene->addLine(200,-50,240,-50,greenPen);
    line = scene->addLine(200,-60,238,-60,greenPen);

    connect(uii->pushButton, SIGNAL(clicked()), p, SLOT( mojSlot()));
    connect(uii->pushButton, SIGNAL(clicked()), p, SLOT( mojSlot()));
    connect(this, SIGNAL(MKSignal()), p, SLOT( mojSlot()));
}

Dialog::~Dialog()
{
    delete uii;
}

void Dialog::NarysujLinie(QPen blackPen, skrzydlo *p)
{
    auto wysokosc = uii->graphicsView->sceneRect().height();
    auto szerokosc = uii->graphicsView->sceneRect().width();

    auto poczatek2Ver = p->GetPoczatek2Ver();
    auto koniec = p->GetKoniec();


    int xPocznew = poczatek2Ver.x - szerokosc/2.0;
    int xKoniecNew = koniec.x - szerokosc/2.0;

    int yPocznew = - (poczatek2Ver.y - wysokosc/2.0);
    int yKoniecew = - (koniec.y - wysokosc/2.0);

    scene->addLine(xPocznew, yPocznew ,xKoniecNew, yKoniecew,blackPen);
}

void Dialog::test()
{
    emit MKSignal();
}

void Dialog::on_pushButton_clicked()
{
    uii->graphicsView->rotate(-2);
    //ellipse->setRotation(2);
    ellipse->rotation();
    //ellipse->setRotation(90);
    emit on_horizontalSlider_valueChanged(7);
}

void Dialog::on_pushButton_2_clicked()
{
    uii->graphicsView->rotate(+2);
    qDebug() << "Wcisnieto przycisk +1";
}

void Dialog::on_horizontalSlider_valueChanged(int value)
{
    int wartosc = value;
    qDebug() << "Wcisnieto przycisk -1";
}

void Dialog::on_horizontalSlider_2_pressed(int value)
{
    qDebug() << "Okkk";
    Dialog::dane = value;    
}

// void Dialog::MKSignal()
// {

// }

