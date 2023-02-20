#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    _comboBoxIndex = 0;
    changeComboBox(_comboBoxIndex);

    connect(ui->cB_Material, &QComboBox::activated, this, &MainWindow::changeComboBox);

    connect(ui->sB_Width, &QSpinBox::editingFinished, this, &MainWindow::calculate);
    connect(ui->sB_Height, &QSpinBox::editingFinished, this, &MainWindow::calculate);
}


MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::changeComboBox(int index) {
    _comboBoxIndex = index;

    int cost = getMaterialCost(index);
    ui->sB_Cost->setValue(cost);

    calculate();
}


int MainWindow::getMaterialCost(int index) {
    switch (index) {
        case 0:
            return 100;
        case 1:
            return 200;
        case 2:
            return 300;
        case 3:
            return 400;
    }

    return 0;
}


void MainWindow::calculate() {
    int res;

    int width = ui->sB_Width->value();
    int height = ui->sB_Height->value();

    int material = getMaterialCost(_comboBoxIndex);

    res = width * height * material;

    QString text = "Итого: ";
    text += QString::number(res);
    ui->tE_Result->setText(text);
}
