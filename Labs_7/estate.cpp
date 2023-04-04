#include "estate.h"

Estate::Estate(QObject *parent): QObject{parent} {
    _owner = "Иванов";
    _age = 18;
    _type = EstateType::ECONOM;
    _residents = 1;
    _area = 25;
    _months = 6;
}


Estate::Estate(QString owner, int age, EstateType type, int residents, int area, int months):
    QObject(nullptr) {

    _owner = owner;
    _age = age;
    _type = type;
    _residents = residents;
    _area = area;
    _months = months;
}


Estate::~Estate () {

}


int Estate::getAge() {
    return _age;
}


int Estate::getArea() {
    return _area;
}


int Estate::getResidents() {
    return _residents;
}


int Estate::getMonths() {
    return _months;
}


int Estate::getType() {
    return _type;
}

QString Estate::getOwner() {
    return _owner;
}
