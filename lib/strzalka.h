#ifndef STRZALKA_H
#define STRZALKA_H

#include <QtCore>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>

QT_BEGIN_NAMESPACE
namespace Ui {
class strzalka;
}
QT_END_NAMESPACE

class strzalka : public QObject
{
    Q_OBJECT
public:

    strzalka();

    void setKierunek(int x, int y);
    void narysuj_strz();

private:
    QGraphicsScene *scene{nullptr};
    QGraphicsItemGroup *m_strzalka{nullptr};
    QGraphicsLineItem *line{nullptr};
};
#endif // STRZALKA_H
