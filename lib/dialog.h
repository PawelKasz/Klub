#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

//#include "plat.h"
#include "skrzydlo.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
public:
    int dane;
    int dane1;
    skrzydlo *wsk_dane;

    explicit Dialog(skrzydlo *p, QWidget *parent = nullptr);
    Dialog(std::vector<std::unique_ptr<skrzydlo>> &skrzydlata_polska);
    ~Dialog();

    void test(int);
    void NarysujLinie(QPen blackPen, skrzydlo *p);

    cieciwa ConvertToQtCoords(const cieciwa &nazwa) const;
    void narysuj_strz(QPen blackPen, skrzydlo *p);

signals:
    void MKSignal();
    void PawSignal();

private slots:
    void on_pushButton_1_clicked();
    void on_pushButton_2_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_pressed(int);
    void testowy_slot();
    void test();

private:
    Ui::Dialog *uii;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse, *ellipse1;
    QGraphicsRectItem *rectangle, *rectangle1, *rectangle2;
    QGraphicsLineItem *line, *line1, *line2;

    QGraphicsLineItem *m_moja_linia{nullptr};
    QGraphicsItemGroup *strzalka{nullptr};

};
#endif // DIALOG_H
