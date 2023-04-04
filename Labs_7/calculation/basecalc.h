#ifndef BASECALC_H
#define BASECALC_H

#include "estate.h"

class BaseCalc {

public:
    explicit BaseCalc(Estate *value);
    virtual ~BaseCalc();

    virtual int getCost();

protected:
    Estate *_estate;

    int _perMeter;
    int _perPerson;
    int _classHouse;
};

#endif // BASECALC_H
