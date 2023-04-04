#include "townhousecalc.h"

TownhouseCalc::TownhouseCalc(QObject *parent): QObject{parent} {

}


int TownhouseCalc::getCost(Estate *value) {
    int perMeter = 33;
    int perPerson = 1500;
    int classHouse = 9;

    int cost = (value->getArea() * perMeter +
                value->getResidents() * perPerson) *
                classHouse * value->getMonths();

    return cost;
}
