#ifndef APARTMENTCALC_H
#define APARTMENTCALC_H

#include "basecalc.h"

class ApartmentCalc : public BaseCalc {

public:
    explicit ApartmentCalc(Estate *value);
    virtual int getCost() override;
};

#endif // APARTMENTCALC_H
