#include "calculationfacade.h"

CalculationFacade::CalculationFacade(QObject *parent): QObject{parent} {
    _apartmentFactory = new ApartmentFactory();
    _cottageFactory = new CottageFactory();
    _luxuriousApartmentFactory = new LuxuriousApartmentFactory();
    _townhouseFactory = new TownhouseFactory();
}


CalculationFacade::~CalculationFacade() {
    delete _apartmentFactory;
    delete _cottageFactory;
    delete _luxuriousApartmentFactory;
    delete _townhouseFactory;
}


int CalculationFacade::getCost(Estate *value) {
    BaseCalc *calculationMethod;

    switch (value->getType()) {
        case Estate::EstateType::ECONOM:
            calculationMethod = _apartmentFactory->factoryMethod(value);
            break;

        case Estate::EstateType::LUXURIOUS:
            calculationMethod = _luxuriousApartmentFactory->factoryMethod(value);
            break;

        case Estate::EstateType::TOWN_HOUSE:
            calculationMethod = _townhouseFactory->factoryMethod(value);
            break;

        case Estate::EstateType::COTTAGE:
            calculationMethod = _cottageFactory->factoryMethod(value);
            break;
    }

    int cost = calculationMethod->getCost();

    delete calculationMethod;
    return cost;
}
