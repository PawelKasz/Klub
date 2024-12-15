#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>

#include "plat.h"
#include "skrzydlo.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT
    int dane;
    int dane1;

public:
    explicit Dialog(skrzydlo *p, QWidget *parent = nullptr);
    ~Dialog();

    void test();

    void NarysujLinie(QPen blackPen, skrzydlo *p);

signals:
    void MKSignal();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();
    void on_horizontalSlider_valueChanged(int value);
    void on_horizontalSlider_2_pressed(int);

private:
    Ui::Dialog *uii;
    QGraphicsScene *scene;
    QGraphicsEllipseItem *ellipse, *ellipse1;
    QGraphicsRectItem *rectangle;
    QGraphicsLineItem *line;
};
#endif // DIALOG_H
