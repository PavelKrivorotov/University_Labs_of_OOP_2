#ifndef COTTAGECALC_H
#define COTTAGECALC_H

#include "basecalc.h"

class CottageCalc : public BaseCalc {

public:
    explicit CottageCalc(Estate *value);
    virtual int getCost() override;
};

#endif // COTTAGECALC_H
