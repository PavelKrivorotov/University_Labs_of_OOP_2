#include "townhousefactory.h"

TownhouseFactory::TownhouseFactory() {

}


TownhouseCalc * TownhouseFactory::factoryMethod(Estate *value) {
    return new TownhouseCalc(value);
}
