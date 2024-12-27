#include "strzalka.h"
#include "qgraphicsitem.h"
#include <QDialog>

strzalka::strzalka()
{}

void strzalka::narysuj_strz(){

    QPen blackPen(Qt::GlobalColor::black);

    m_strzalka = new QGraphicsItemGroup;
    scene->addItem(m_strzalka);
    blackPen.setWidth(3);
    m_strzalka->addToGroup(line = scene->addLine(0,10,50,10,blackPen));
    m_strzalka->addToGroup(line = scene->addLine(50,10,50,20,blackPen));
    m_strzalka->addToGroup(line = scene->addLine(50,20,70,0,blackPen));
    m_strzalka->addToGroup(line = scene->addLine(50,-20,70,0,blackPen));
    m_strzalka->addToGroup(line = scene->addLine(50,-10,50,-20,blackPen));
    m_strzalka->addToGroup(line = scene->addLine(0,-10,50,-10,blackPen));
    m_strzalka->addToGroup(line = scene->addLine(0,-10,0,10,blackPen));

    m_strzalka->setX(-310);
    m_strzalka->setFlag(QGraphicsItem::ItemIsMovable);
}
