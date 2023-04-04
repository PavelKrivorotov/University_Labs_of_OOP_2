#ifndef BASEFACTORY_H
#define BASEFACTORY_H

#include "calculation/basecalc.h"

class BaseFactory {

public:
    explicit BaseFactory();
    virtual ~BaseFactory();
    virtual BaseCalc * factoryMethod(Estate *value);
};

#endif // BASEFACTORY_H
