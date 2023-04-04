#ifndef CALCULATIONFACADE_H
#define CALCULATIONFACADE_H

#include <QObject>
#include "estate.h"
#include "facade/apartmentcalc.h"
#include "facade/luxuriousapartmentcalc.h"
#include "facade/townhousecalc.h"
#include "facade/cottagecalc.h"

class CalculationFacade : public QObject {
    Q_OBJECT

public:
    explicit CalculationFacade(QObject *parent = nullptr);

    static int getCost(Estate *value);
};

#endif // CALCULATIONFACADE_H
