#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    calculate();

    connect(ui->pBtn_calculate, &QPushButton::clicked, this, &MainWindow::calculate);

    connect(ui->cB_closet, &QCheckBox::clicked, this, &MainWindow::calculate);
    connect(ui->cB_table, &QCheckBox::clicked, this, &MainWindow::calculate);
    connect(ui->cB_curtains, &QCheckBox::clicked, this, &MainWindow::calculate);
    connect(ui->cB_lamps, &QCheckBox::clicked, this, &MainWindow::calculate);
}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::calculate() {
    int main_section;
    main_section = 0;

    int addition_section;
    addition_section = 0;

    int discount;
    discount = 0;

    int result;
    result = 0;

    QString text;
    text += "Main section:\n";

    bool cB_room = ui->cB_room->isChecked();
    int sB_room = ui->sB_room->value();
    main_section += addCost(cB_room, sB_room);
    text += formatToString(cB_room, sB_room);

    text += "\nAddition section:\n";

    bool cB_table = ui->cB_table->isChecked();
    int sB_table = ui->sB_table->value();
    addition_section += addCost(cB_table, sB_table);
    text += formatToString(cB_table, sB_table);

    bool cB_closet = ui->cB_closet->isChecked();
    int sB_closet = ui->sB_closet->value();
    addition_section += addCost(cB_closet, sB_closet);
    text += formatToString(cB_closet, sB_closet);

    bool cB_curtains = ui->cB_curtains->isChecked();
    int sB_curtains = ui->sB_curtains->value();
    addition_section += addCost(cB_curtains, sB_curtains);
    text += formatToString(cB_curtains, sB_curtains);

    bool cB_lamps = ui->cB_lamps->isChecked();
    int sB_lamps = ui->sB_lamps->value();
    addition_section += addCost(cB_lamps, sB_lamps);
    text += formatToString(cB_lamps, sB_lamps);

    text += "\nDiscount:\n";
    if (cB_table && cB_closet && cB_curtains && cB_lamps) {
        discount = addition_section * 0.1;
    }
    text += formatToString(true, discount, "-");

    text += "\nResult\n";
    result = main_section + addition_section - discount;
    text += formatToString(true, result, "");

    ui->tE_result->setText(text);
}


int MainWindow::addCost(bool state, int value) {
    if (state) {
        return value;
    }

    return 0;
}


QString MainWindow::formatToString(bool state, int value, QString sign) {
    if (state) {
        QString str = "\t";
        str += sign;
        str += QString::number(value);
        str += "\n";
        return str;
    }

    return QString("");
}
