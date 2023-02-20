#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    calculate();

    connect(ui->rB_3x4, &QRadioButton::clicked, this, &MainWindow::calculate);
    connect(ui->rB_9x12, &QRadioButton::clicked, this, &MainWindow::calculate);
    connect(ui->rB_15x30, &QRadioButton::clicked, this, &MainWindow::calculate);

    connect(ui->rB_gloss, &QRadioButton::clicked, this, &MainWindow::calculate);
    connect(ui->rB_matte, &QRadioButton::clicked, this, &MainWindow::calculate);

    connect(ui->sB_Count, &QSpinBox::editingFinished, this, &MainWindow::calculate);
}


MainWindow::~MainWindow() {
    delete ui;
}


int MainWindow::getFormatCost() {
    if (ui->rB_3x4->isChecked()) { return 10; }
    else if (ui->rB_9x12->isChecked()) { return 20; }
    else if (ui->rB_15x30->isChecked()) { return 30; }
    else { return 0; }
}


int MainWindow::getMaterialCost() {
    if (ui->rB_gloss->isChecked()) { return 100; }
    else if (ui->rB_matte->isChecked()) { return 200; }
    else { return 0; }
}


void MainWindow::calculate() {
    int formatCost = getFormatCost();
    int materialCost = getMaterialCost();
    int count = ui->sB_Count->value();

    int res = formatCost * materialCost * count;

    QString text = "Итого: ";
    text += QString::number(res);
    ui->tE_Result->setText(text);
}
