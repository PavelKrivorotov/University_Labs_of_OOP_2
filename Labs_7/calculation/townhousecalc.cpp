#include "townhousecalc.h"

TownhouseCalc::TownhouseCalc(Estate *value): BaseCalc(value) {
    _perMeter = 33;
    _classHouse = 9;
}


int TownhouseCalc::getCost() {
    int cost = (_estate->getArea() * _perMeter +
                _estate->getResidents() * _perPerson) *
                _classHouse * _estate->getMonths();

    return cost;
}
