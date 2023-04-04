#ifndef LUXURIOUSAPARTMENTCALC_H
#define LUXURIOUSAPARTMENTCALC_H

#include "basecalc.h"

class LuxuriousApartmentCalc : public BaseCalc {

public:
    explicit LuxuriousApartmentCalc(Estate *value);
    virtual int getCost() override;
};

#endif // LUXURIOUSAPARTMENTCALC_H
