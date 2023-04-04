#include "basecalc.h"

BaseCalc::BaseCalc(Estate *value) {
    _estate = value;

    _perMeter = 11;
    _perPerson = 1500;
    _classHouse = 3;
}


BaseCalc::~BaseCalc() {

}


int BaseCalc::getCost() {

}
