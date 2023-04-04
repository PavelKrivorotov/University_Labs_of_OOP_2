#include "apartmentcalc.h"

ApartmentCalc::ApartmentCalc(Estate *value): BaseCalc(value) {

}


int ApartmentCalc::getCost() {
    int cost = (_estate->getArea() * _perMeter +
                _estate->getResidents() * _perPerson) *
                _classHouse * _estate->getMonths();

    return cost;
}
