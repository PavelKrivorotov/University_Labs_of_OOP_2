#ifndef STATES_H
#define STATES_H

#include <QObject>
#include "estate.h"

class States : public QObject {
    Q_OBJECT

public:
    explicit States(QObject *parent = nullptr);
    virtual ~States();

    void undo();

    bool hasStates();

    Estate * getActualData();

    void add(Estate* data);

private:
    QList<Estate*> _array;
    Estate *_actualData;

signals:
    void notifyObservers();
};

#endif // STATES_H
