#ifndef APARTMENTFACTORY_H
#define APARTMENTFACTORY_H

#include "basefactory.h"
#include "calculation/apartmentcalc.h"

class ApartmentFactory: public BaseFactory {

public:
    explicit ApartmentFactory();
    virtual ApartmentCalc * factoryMethod(Estate *value) override;
};

#endif // APARTMENTFACTORY_H
