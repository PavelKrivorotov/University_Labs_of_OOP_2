#include "apartmentcalc.h"

ApartmentCalc::ApartmentCalc(QObject *parent): QObject{parent} {

}


int ApartmentCalc::getCost(Estate *value) {
    int perMeter = 11;
    int perPerson = 1500;
    int classHouse = 3;

    int cost = (value->getArea() * perMeter +
                value->getResidents() * perPerson) *
                classHouse * value->getMonths();

    return cost;
}
