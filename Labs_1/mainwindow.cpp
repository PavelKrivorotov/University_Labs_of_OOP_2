#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "math.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    message = new QMessageBox(this);
    message->setWindowModality(Qt::WindowModality::WindowModal);
    message->setIcon(QMessageBox::Critical);
    message->setWindowTitle("Error");
    message->setText("Result with dived by 0 is undefined!");

    connect(ui->pBtn_plus, &QPushButton::clicked, this, &MainWindow::plus);
    connect(ui->pBtn_minus, &QPushButton::clicked, this, &MainWindow::minus);
    connect(ui->pBtn_multyple, &QPushButton::clicked, this, &MainWindow::multyple);
    connect(ui->pBtn_division, &QPushButton::clicked, this, &MainWindow::division);
    connect(ui->pBtn_remainde, &QPushButton::clicked, this, &MainWindow::remainde);
    connect(ui->pBtn_clear, &QPushButton::clicked, this, &MainWindow::clear);
}


MainWindow::~MainWindow() {
    delete ui;
    delete message;
}


void MainWindow::plus() {
    double res;
    res = ui->dSB_Value1->value() + ui->dSB_Value2->value();

    ui->dSB_Result->setValue(res);
}


void MainWindow::minus() {
    double res;
    res = ui->dSB_Value1->value() - ui->dSB_Value2->value();

    ui->dSB_Result->setValue(res);
}


void MainWindow::multyple() {
    double res;
    res = ui->dSB_Value1->value() * ui->dSB_Value2->value();

    ui->dSB_Result->setValue(res);
}


void MainWindow::division() {
    double res;

    if (ui->dSB_Value2->value() == 0.0) {
        clear();

        message->show();
        return;
    }

    res = ui->dSB_Value1->value() / ui->dSB_Value2->value();

    ui->dSB_Result->setValue(res);
}


void MainWindow::remainde() {
    double value1 = ui->dSB_Value1->value();
    double value2 = ui->dSB_Value2->value();

    if (value2 == 0.0) {
        clear();

        message->show();
        return;
    }

    double res = fmod(value1, value2);
    ui->dSB_Result->setValue(res);
}


void MainWindow::clear() {
    ui->dSB_Value1->setValue(0.0);
    ui->dSB_Value2->setValue(0.0);
    ui->dSB_Result->setValue(0.0);
}
