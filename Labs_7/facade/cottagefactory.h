#ifndef COTTAGEFACTORY_H
#define COTTAGEFACTORY_H

#include "basefactory.h"
#include "calculation/cottagecalc.h"

class CottageFactory: public BaseFactory {

public:
    explicit CottageFactory();
    virtual CottageCalc * factoryMethod(Estate *value) override;
};

#endif // COTTAGEFACTORY_H
