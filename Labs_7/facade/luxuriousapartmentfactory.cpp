#include "luxuriousapartmentfactory.h"

LuxuriousApartmentFactory::LuxuriousApartmentFactory() {

}


LuxuriousApartmentCalc * LuxuriousApartmentFactory::factoryMethod(Estate *value) {
    return new LuxuriousApartmentCalc(value);
}
