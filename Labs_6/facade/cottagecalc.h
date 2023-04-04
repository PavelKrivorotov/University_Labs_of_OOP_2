#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include <QObject>
#include "estate.h"

class CottageCalc : public QObject
{
    Q_OBJECT
public:
    explicit CottageCalc(QObject *parent = nullptr);

    static int getCost(Estate *value);
};

#endif // COTTAGECALC_H
