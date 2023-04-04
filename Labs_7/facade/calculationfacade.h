#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QObject>

#include "apartmentfactory.h"
#include "cottagefactory.h"
#include "luxuriousapartmentfactory.h"
#include "townhousefactory.h"

class CalculationFacade : public QObject {
    Q_OBJECT

public:
    explicit CalculationFacade(QObject *parent = nullptr);
    ~CalculationFacade();

     int getCost(Estate *value);

private:
    ApartmentFactory *_apartmentFactory;
    CottageFactory *_cottageFactory;
    LuxuriousApartmentFactory *_luxuriousApartmentFactory;
    TownhouseFactory *_townhouseFactory;
};

#endif // CALCULATIONFACADE_H
