#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent): QWidget(parent), ui(new Ui::Widget) {
    ui->setupUi(this);

    _info = new States(this);


    connect(_info, &States::notifyObservers, this, &Widget::update);
    connect(ui->btnCalc, &QPushButton::clicked, this, &Widget::btnCalcPressed);
    connect(ui->btnUndo, &QPushButton::clicked, this, &Widget::btnUndoPressed);
}


Widget::~Widget() {
    delete ui;
    delete _info;
}


void Widget::update() {
    Estate *value = _info->getActualData();
    if (value != nullptr) { fillForm(value); }

    ui->btnUndo->setEnabled(_info->hasStates());
    value = nullptr;
}


void Widget::btnCalcPressed() {
    Estate *value = processForm();
    showCost(value);
    _info->add(value);

    ui->btnUndo->setEnabled(true);
    value = nullptr;
}


void Widget::btnUndoPressed() {
    _info->undo();
    ui->cost->clear();
}


Estate *Widget::processForm() {
    QString owner = ui->owner->text();
    int age = ui->age->value();

    Estate::EstateType type;
    switch (ui->estateType->currentIndex()) {
        case 0:
            type = Estate::EstateType::ECONOM;
            break;

        case 1:
            type = Estate::EstateType::LUXURIOUS;
            break;

        case 2:
            type = Estate::EstateType::TOWN_HOUSE;
            break;

        case 3:
            type = Estate::EstateType::COTTAGE;
            break;
    }

    int residents = ui->residents->value();
    int area = ui->area->value();

    int months;
    switch (ui->period->currentIndex()) {
        case 0:
            months = 6;
            break;

        case 1:
            months = 12;
            break;

        case 2:
            months = 18;
            break;
    }

    Estate *value = new Estate(owner, age, type, residents, area, months);
    return value;
}


void Widget::fillForm(Estate *value) {
    ui->owner->setText(value->getOwner());
    ui->age->setValue(value->getAge());

    switch (value->getType()) {
        case Estate::EstateType::ECONOM:
            ui->estateType->setCurrentIndex(0);
            break;

        case Estate::EstateType::LUXURIOUS:
            ui->estateType->setCurrentIndex(1);
            break;

        case Estate::EstateType::TOWN_HOUSE:
            ui->estateType->setCurrentIndex(2);
            break;

        case Estate::EstateType::COTTAGE:
            ui->estateType->setCurrentIndex(3);
            break;
    }

    ui->residents->setValue(value->getResidents());
    ui->area->setValue(value->getArea());

    switch (value->getMonths()) {
        case 6:
            ui->period->setCurrentIndex(0);
            break;

        case 12:
            ui->period->setCurrentIndex(1);
            break;

        case 18:
            ui->period->setCurrentIndex(2);
            break;
    }
}


void Widget::showCost(Estate *value) {
    int cost = CalculationFacade::getCost(value);
    ui->cost->setText(QString::number(cost));
}
