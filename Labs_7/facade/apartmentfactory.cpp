#include "apartmentfactory.h"

ApartmentFactory::ApartmentFactory() {

}


ApartmentCalc * ApartmentFactory::factoryMethod(Estate *value) {
    return new ApartmentCalc(value);
}
