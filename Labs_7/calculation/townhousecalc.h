#ifndef TOWNHOUSECALC_H
#define TOWNHOUSECALC_H

#include "basecalc.h"

class TownhouseCalc : public BaseCalc {

public:
    explicit TownhouseCalc(Estate *value);
    virtual int getCost() override;
};

#endif // TOWNHOUSECALC_H
