#include "luxuriousapartmentcalc.h"

LuxuriousApartmentCalc::LuxuriousApartmentCalc(QObject *parent): QObject{parent} {

}


int LuxuriousApartmentCalc::getCost(Estate *value) {
    int perMeter = 22;
    int perPerson = 1500;
    int classHouse = 6;

    int cost = (value->getArea() * perMeter +
                value->getResidents() * perPerson) *
                classHouse * value->getMonths();

    return cost;
}
