#include "cottagecalc.h"

CottageCalc::CottageCalc(QObject *parent): QObject{parent} {

}


int CottageCalc::getCost(Estate *value) {
    int perMeter = 44;
    int perPerson = 1500;
    int classHouse = 12;

    int cost = (value->getArea() * perMeter +
                value->getResidents() * perPerson) *
                classHouse * value->getMonths();

    return cost;
}
