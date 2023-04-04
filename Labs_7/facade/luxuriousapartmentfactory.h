#ifndef LUXURIOUSAPARTMENTFACTORY_H
#define LUXURIOUSAPARTMENTFACTORY_H

#include "basefactory.h"
#include "calculation/luxuriousapartmentcalc.h"

class LuxuriousApartmentFactory: public BaseFactory {

public:
    explicit LuxuriousApartmentFactory();
    virtual LuxuriousApartmentCalc * factoryMethod(Estate *value) override;
};

#endif // LUXURIOUSAPARTMENTFACTORY_H
