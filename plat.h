#ifndef PLAT_H
#define PLAT_H

#include <QObject>

class plat : public QObject
{
    Q_OBJECT

public:
    explicit plat(QObject *parent = nullptr);

signals:

};

#endif // PLAT_H
