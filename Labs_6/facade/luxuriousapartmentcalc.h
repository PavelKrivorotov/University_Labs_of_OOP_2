#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include <QObject>
#include "estate.h"

class LuxuriousApartmentCalc : public QObject {
    Q_OBJECT

public:
    explicit LuxuriousApartmentCalc(QObject *parent = nullptr);

    static int getCost(Estate *value);
};

#endif // LUXURIOUSAPARTMENTCALC_H
