#include "cottagecalc.h"

CottageCalc::CottageCalc(Estate *value): BaseCalc(value) {
    _perMeter = 44;
    _classHouse = 12;
}


int CottageCalc::getCost() {
    int cost = (_estate->getArea() * _perMeter +
                _estate->getResidents() * _perPerson) *
                _classHouse * _estate->getMonths();

    return cost;
}
