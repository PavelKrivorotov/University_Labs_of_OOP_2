#include "cottagefactory.h"

CottageFactory::CottageFactory() {

}


CottageCalc * CottageFactory::factoryMethod(Estate *value) {
    return new CottageCalc(value);
}
