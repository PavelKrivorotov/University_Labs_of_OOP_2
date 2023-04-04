#include "states.h"

States::States(QObject *parent): QObject{parent} {
    _actualData = nullptr;
}


States::~States() {
    if (_actualData) {
        delete _actualData;
        _actualData = nullptr;
    }

    qDeleteAll(_array);
    _array.clear();
}


void States::undo() {
    if (_actualData) { delete _actualData; }

    if (hasStates()) {
        _actualData = _array.last();
        _array.removeLast();
    }

    else { _actualData = nullptr; }

    emit notifyObservers();
}


bool States::hasStates() {
    if (_array.isEmpty()) { return false; }
    return true;
}


Estate * States::getActualData() {
    return _actualData;
}


void States::add(Estate* data) {
    _actualData = nullptr;
    _array.append(data);
}
