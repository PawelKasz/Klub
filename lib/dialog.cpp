#include "dialog.h"
//#include "plat.h"
#include "skrzydlo.h"
#include "ui_dialog_1.h"
#include "QGraphicsView"
#include <QGraphicsItem>
#include <QDebug>
#include <QPushButton>


Dialog::Dialog(skrzydlo *p, QWidget *parent) //stary konstruktor
    : QDialog(parent)
    , uii(new Ui::Dialog)
{
    uii->setupUi(this);

    scene = new QGraphicsScene (this);
    uii->graphicsView->setScene(scene);

    scene->setSceneRect(-329, -236, 659, 475);  //To ustawia rozmiar sceny

    QBrush redBrush(Qt::red);
    QBrush blueBrush(Qt::blue);
    QBrush greenBrush(Qt::green);
    QPen blackPen(Qt::black);
    QPen redPen(Qt::red);
    QPen greenPen(Qt::green);
    QPen pomarPen(QColor(81,72,151));
    blackPen.setWidth(3);
    greenPen.setWidth(5);
    pomarPen.setWidth(4);

/*
    QGraphicsItemGroup *strzalka;
    strzalka = new QGraphicsItemGroup;
    scene->addItem(strzalka);
    strzalka->addToGroup(line1 = scene->addLine(0,10,50,10,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,10,50,20,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,20,70,0,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,-20,70,0,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,-10,50,-20,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(0,-10,50,-10,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(0,-10,0,10,blackPen));

    strzalka->setX(220);
strzalka->setFlag(QGraphicsItem::ItemIsMovable);
*/

    //ellipse = scene->addEllipse(-150, -200,300,100,blackPen,redBrush);
    //ellipse1 = scene->addEllipse(-50, -100, 100, 100,blackPen,greenBrush);

    rectangle = scene->addRect(-50, 0, 5, 5);

    QTransform tr;                  //Transformacja
    tr.rotate(45);
    rectangle->setTransform(tr);

    rectangle->setFlag(QGraphicsItem::ItemIsMovable);

    //rectangle1 = scene->addRect(0, -50 , 5, 5);

    //rectangle2 = scene->addRect(50, 0, 5, 5);
    //rectangle2->setX(200);
    //rectangle2->setY(40);
    //rectangle2->setFlag(QGraphicsItem::ItemIsMovable);

    //rectangle = scene->addRect(0, 50, 5, 5);
    //rectangle->setFlag(QGraphicsItem::ItemIsMovable);


    NarysujLinie(pomarPen, p);
    narysuj_strz(redPen, p);

    //line1 = scene->addLine(-50,100,200,190,blackPen);
    line2 = scene->addLine(-54, -1, -124,-1,greenPen);
    line = scene->addLine(0, -103, 0,-173,greenPen);
    //line = scene->addLine(200,-50,240,-50,greenPen);
    line = scene->addLine(59, -1, 120, -1,greenPen);

    connect(uii->pushButton_2, SIGNAL(clicked()), this, SLOT(test()));      //DZIALA
    connect(uii->pushButton_1, SIGNAL(clicked()), this, SLOT(quit()));
    connect(uii->pushButton_1, SIGNAL(clicked()), this, SLOT(testowy_slot())); //DZIALA
    connect(this, SIGNAL(MKSignal()), p, SLOT(quit()));
    //connect(uii->pushButton_1, SIGNAL(clicked()), this, SLOT(&wsk_dane));
    connect(uii->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(test()));  //Dziala

}

Dialog::Dialog(std::vector<std::unique_ptr<skrzydlo> > &skrzydlata_polska) : QDialog(nullptr) //nowy
    , uii(new Ui::Dialog)
{
    uii->setupUi(this);
    QPen pomarPen(QColor(81,72,151));
    scene = new QGraphicsScene (this);
    uii->graphicsView->setScene(scene);

    for(auto &i: skrzydlata_polska)
    {
        NarysujLinie(pomarPen, i.get());
    }
}

Dialog::~Dialog()
{
    delete uii;
}


cieciwa Dialog::ConvertToQtCoords(cieciwa const &nazwa) const
{
    cieciwa wynik{};
    wynik.poczatek.x = nazwa.poczatek.x;
    wynik.koniec.x = nazwa.koniec.x;

    wynik.poczatek.y = -nazwa.poczatek.y;
    wynik.koniec.y = -nazwa.koniec.y;

    return wynik;
}

void Dialog::NarysujLinie(QPen blackPen, skrzydlo *p)
{
    //auto wysokosc = uii->graphicsView->sceneRect().height();
    //auto szerokosc = uii->graphicsView->sceneRect().width();

    auto poczatek2Ver = p->GetPoczatek2Ver();
    auto koniec = p->GetKoniec();

    //int xPocznew = 70;
    //int xPocznew = poczatek2Ver.x;
    //int xKoniecNew = -112;
    //int xKoniecNew = koniec.x;
    //int yPocznew = -70;
    //int yPocznew = wysokosc/2.0 - poczatek2Ver.y;
    //int yPocznew = -(poczatek2Ver.y);
    //int yKoniecew = 112;
    //int yKoniecew = (wysokosc/2.0 + koniec.y) - szerokosc/2.0;
    // int yKoniecew = (koniec.y)-(koniec.y * 2);
    //int yKoniecew = -(koniec.y);

    // scene->addLine(xPocznew, yPocznew ,xKoniecNew, (yKoniecew),blackPen);


    auto const cieciwa = p->GetCieciwa();
    auto const newcieciwa = ConvertToQtCoords(cieciwa);

    m_moja_linia = scene->addLine(newcieciwa.poczatek.x, newcieciwa.poczatek.y, newcieciwa.koniec.x, newcieciwa.koniec.y,blackPen);

}

void Dialog::narysuj_strz(QPen blackPen, skrzydlo *p){

    QGraphicsItemGroup *strzalka;
    strzalka = new QGraphicsItemGroup;
    scene->addItem(strzalka);
    strzalka->addToGroup(line1 = scene->addLine(0,10,50,10,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,10,50,20,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,20,70,0,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,-20,70,0,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(50,-10,50,-20,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(0,-10,50,-10,blackPen));
    strzalka->addToGroup(line1 = scene->addLine(0,-10,0,10,blackPen));

    strzalka->setX(-310);
    strzalka->setFlag(QGraphicsItem::ItemIsMovable);

}

void Dialog::test(){
    emit MKSignal();
    qDebug() << "TEST po zmianie";
    dane = 100;
    wsk_dane->srodekSkrzy;
}

void Dialog::on_pushButton_1_clicked()
{
    uii->graphicsView->rotate(-2);
    qDebug() << "Wcisnieto przycisk -1";
    //ellipse->setRotation(2);
    //ellipse->rotation();
    //ellipse->setRotation(90);
    //emit on_horizontalSlider_valueChanged(1);
}

void Dialog::on_pushButton_2_clicked()
{
    uii->graphicsView->rotate(+2);
    qDebug() << "Wcisnieto przycisk +1";

}

void Dialog::on_horizontalSlider_valueChanged(int )
{
    //int wartosc = value;
    qDebug() << "Wcisnieto przycisk slider Kier_wiatru";

    // uii->graphicsView->rotate(90);                      //Zamienić na obracanie skrzydla

    auto const poprzedni_kat = m_moja_linia->rotation();
    m_moja_linia->setRotation(poprzedni_kat+10);
    //scene->removeItem(m_moja_linia);

    QTransform tr;
    tr.translate(-100, -100);
    m_moja_linia->setTransform(tr);
}

void Dialog::on_horizontalSlider_2_pressed(int value)
{
    qDebug() << "Okkk";
    Dialog::dane = value;    
}

void Dialog::testowy_slot(){
    qDebug() << "zzzzzzzzz";
}
