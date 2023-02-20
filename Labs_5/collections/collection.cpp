#include "collection.h"

#include <QFile>
#include <QListIterator>

#include <QDebug>

Collection::Collection() {
    _listOfCollection = new QList<int>;
}


Collection::Collection(Collection *collection) {
    _listOfCollection = new QList<int>(*collection->_listOfCollection);
}


Collection::~Collection() {
    delete _listOfCollection;
}


int Collection::getElementAtIndex(int index) {
    return _listOfCollection->at(index);
}


void Collection::removeElementByIndex(int index) {
    _listOfCollection->removeAt(index);
}


void Collection::removeAllElementsByValue(int value) {
    _listOfCollection->removeAll(value);
}


void Collection::addElementByIndex(int index, int value) {
    _listOfCollection->insert(index, value);
}


int Collection::sumOfElements() {
    int sum = 0;
    for (int index = 0; index < _listOfCollection->size(); index++) {
        sum += _listOfCollection->at(index);
    }

    return sum;
}

int Collection::sumOfEvenElements() {
    int sum = 0;
    for (int index = 0; index < _listOfCollection->size(); index += 2) {
        sum += _listOfCollection->at(index);
    }

    return sum;
}


void Collection::question1() {
    QList<int>::iterator iter1 = _listOfCollection->begin();
    QList<int>::iterator iter_last_zero = _listOfCollection->begin();

    for (;iter1 < _listOfCollection->end(); iter1++) {
        if (*iter1 == 0) {
            QList<int>::iterator temp = iter1;
            for(;temp > iter_last_zero; temp--) {
                *temp = *(temp - 1);
            }

            *iter_last_zero = 0;
            iter_last_zero++;
        }
    }
}


int Collection::question2() {
    int sum = 0;

    QList<int>::iterator start = _listOfCollection->begin();
    QList<int>::iterator stop = _listOfCollection->begin();

    while (start < _listOfCollection->end()) {
        int value = *start;
        if (value > 0) {
            break;
        }

        start++;
    }

    QList<int>::iterator temp = _listOfCollection->begin();
    while (temp < _listOfCollection->end()) {
        int value = *temp;
        if (value > 0) {
            stop = temp;
        }

        temp++;
    }

    start++;
    while (start < stop) {
        sum += *start;
        start++;
    }

    return sum;
}


void Collection::parseCollectionFile( QString pathToFile) {
    QFile file(pathToFile);
    file.open(QIODevice::ReadOnly | QIODevice::Text);

    while (!file.atEnd()) {
        QByteArray line = file.readLine();
        _listOfCollection->append(line.toInt());
    }

    file.close();
}


void Collection::renderCollectionFile(QString text, QString pathToFile) {
    QFile file(pathToFile);
    file.open(QIODevice::WriteOnly | QIODevice::Text);

    file.write(text.toUtf8());
    file.close();
}


QString Collection::toText() {
    QString text;

    QListIterator<int> item(*_listOfCollection);
    while (item.hasNext()) {
        text += QString::number(item.next());
        text += "\n";
    }

    return text;
}


void Collection::clear() {
    _listOfCollection->clear();
}


bool Collection::validateIndexFromGet(int index) {
    if (index < _listOfCollection->size()) { return true; }
    return false;
}


bool Collection::validateIndexFromAdd(int index) {
    if (index < _listOfCollection->size() + 1) { return true; }
    return false;
}


bool Collection::validateValueContains(int value) {
    if (_listOfCollection->contains(value)) { return true; }
    return false;
}


bool Collection::validateEmptyCollection() {
    if (!_listOfCollection->isEmpty()) { return true; }
    return false;
}
