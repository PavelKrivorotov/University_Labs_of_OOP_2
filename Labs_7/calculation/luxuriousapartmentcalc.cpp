#include "luxuriousapartmentcalc.h"

LuxuriousApartmentCalc::LuxuriousApartmentCalc(Estate *value): BaseCalc(value) {
    _perMeter = 22;
    _classHouse = 6;
}


int LuxuriousApartmentCalc::getCost() {
    int cost = (_estate->getArea() * _perMeter +
                _estate->getResidents() * _perPerson) *
                _classHouse * _estate->getMonths();

    return cost;
}
