#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsItemGroup>
//#include "plat.h"
#include "skrzydlo.h"
#include "wiatr.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
public:
    int dane = 0;
    int dane1;
    int *wsk_dane = &dane;

    Dialog(skrzydlo *skrzyd, Wiatr* wia, QWidget *parent = nullptr);   // Główny konstruktor
    ~Dialog();

    void NarysujLinie(QPen blackPen, skrzydlo *p);
    cieciwa ConvertToQtCoords(const cieciwa &nazwa) const;

signals:
    void MKSignal();
    void PawSignal();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_horizontalSlider_1_valueChanged(int value);
    void on_horizontalSlider_2_pressed(int);
    void test();
    void testowy_slot();

private:
    skrzydlo *m_skrzydlo{nullptr};
    Wiatr *m_wiatr{nullptr};
    Ui::Dialog *uii{nullptr};

    QGraphicsScene *scene{nullptr};
    QGraphicsEllipseItem *ellipse, *ellipse1;
    QGraphicsRectItem *rectangle, *rectangle1, *rectangle2;
    QGraphicsLineItem *line, *line1, *line2;

    QGraphicsLineItem *m_moja_linia{nullptr};
};
#endif // DIALOG_H
