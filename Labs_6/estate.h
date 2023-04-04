#ifndef ESTATE_H
#define ESTATE_H

#include <QObject>

class Estate : public QObject {
    Q_OBJECT

public:
    enum EstateType {
        ECONOM,
        LUXURIOUS,
        TOWN_HOUSE,
        COTTAGE
    };

    explicit Estate(QObject *parent = nullptr);
    Estate(QString owner, int age, EstateType type, int residents, int area, int months);
    virtual ~Estate();

    int getAge();

    int getArea();

    int getResidents();

    int getMonths();

    int getType();

    QString getOwner();

private:
    int _age;
    int _area;
    int _residents;
    int _months;
    EstateType _type;
    QString _owner;
};

#endif // ESTATE_H
