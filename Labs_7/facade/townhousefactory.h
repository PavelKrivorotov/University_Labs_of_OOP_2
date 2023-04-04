#ifndef TOWNHOUSEFACTORY_H
#define TOWNHOUSEFACTORY_H

#include "basefactory.h"
#include "calculation/townhousecalc.h"

class TownhouseFactory: public BaseFactory {

public:
    explicit TownhouseFactory();
    virtual TownhouseCalc * factoryMethod(Estate * value) override;
};

#endif // TOWNHOUSEFACTORY_H
