#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    _openFileDialog = new QFileDialog(this);
    _closeFileDialog = new QFileDialog(this);

    _message = new QMessageBox(this);

    _openFileName = QString();
    _saveFileName = QString();

    _currentCollection = new Collection();
    _updateCollection = new Collection();


    connect(ui->pBtn_showElemOfIndex, &QPushButton::clicked,
            this, &MainWindow::showElementOfIndex);
    connect(ui->pBtn_removeElemOfIndex, &QPushButton::clicked,
            this, &MainWindow::removeElemOfIndex);
    connect(ui->pBtn_removeElemOfValue, &QPushButton::clicked,
            this, &MainWindow::removeElemOfValue);

    connect(ui->pBtn_addElem, &QPushButton::clicked, this, &MainWindow::addElement);
    connect(ui->pBtn_sumOfElems, &QPushButton::clicked,
            this, &MainWindow::calculateSumOfElements);
    connect(ui->pBtn_sumOfEvenValues, &QPushButton::clicked,
            this, &MainWindow::calculateSumOfEvenElements);

    connect(ui->pBtn_question1, &QPushButton::clicked, this, &MainWindow::question1);
    connect(ui->pBtn_question2, &QPushButton::clicked, this, &MainWindow::question2);

    connect(ui->pBtn_takeCollectionFromFile, &QPushButton::clicked,
            this, &MainWindow::showOpenFileDialog);
    connect(_openFileDialog, &QFileDialog::fileSelected, this, &MainWindow::setOpenFileName);

    connect(ui->pBtn_saveCollectionInFile, &QPushButton::clicked,
            this, &MainWindow::showCloseFileDialog);
    connect(_closeFileDialog, &QFileDialog::fileSelected, this, &MainWindow::saveNewFile);

    connect(ui->pBtn_clearCollection, &QPushButton::clicked, this, &MainWindow::clear);
}


MainWindow::~MainWindow() {
    delete ui;

    delete _openFileDialog;
    delete _closeFileDialog;

    delete _message;

    delete _currentCollection;
    delete _updateCollection;
}


void MainWindow::showElementOfIndex() {
    int index = ui->sB_indexOfElem->value();

    if (!_updateCollection->validateIndexFromGet(index)) {
        showErrorMessage("Error Index", "Input index is not a valid!");
        clearFormMetadata();
        return;
    }

    int value = _updateCollection->getElementAtIndex(index);
    ui->sB_valueOfElem->setValue(value);
}


void MainWindow::removeElemOfIndex() {
    int index = ui->sB_indexOfElem->value();

    if (!_updateCollection->validateIndexFromGet(index)) {
        showErrorMessage("Error Index", "Input index is not a valid!");
        clearFormMetadata();
        return;
    }

    clearFormMetadata();
    clearFormResult();

    _updateCollection->removeElementByIndex(index);

    QString text = _updateCollection->toText();
    ui->tE_updateCollection->setText(text);
}


void MainWindow::removeElemOfValue() {
    int value = ui->sB_valueOfElem->value();

    if (!_updateCollection->validateValueContains(value)) {
        showErrorMessage("Error Value", "Input value not containts of collection!");
        clearFormMetadata();
    }

    clearFormMetadata();
    clearFormResult();

    _updateCollection->removeAllElementsByValue(value);

    QString text = _updateCollection->toText();
    ui->tE_updateCollection->setText(text);
}


void MainWindow::addElement() {
    int index = ui->sB_indexOfElem->value();
    int value = ui->sB_valueOfElem->value();

    if (!_updateCollection->validateIndexFromAdd(index)) {
        showErrorMessage("Error Index", "Input index is not a valid!");
        clearFormMetadata();
        return;
    }

    _updateCollection->addElementByIndex(index, value);

    clearFormMetadata();
    clearFormResult();

    QString text = _updateCollection->toText();
    ui->tE_updateCollection->setText(text);
}


void MainWindow::calculateSumOfElements() {
    if (!_updateCollection->validateEmptyCollection()) {
        showErrorMessage("Error Empty", "This collection is empty!");
        return;
    }

    int sum = _updateCollection->sumOfElements();
    ui->lE_resultSum->setText(QString::number(sum));
}


void MainWindow::calculateSumOfEvenElements() {
    if (!_updateCollection->validateEmptyCollection()) {
        showErrorMessage("Error Empty", "This collection is empty!");
        return;
    }

    int sum = _updateCollection->sumOfEvenElements();
    ui->lE_resultSum->setText(QString::number(sum));
}


void MainWindow::question1() {
    if (!_updateCollection->validateEmptyCollection()) {
        showErrorMessage("Error Empty", "This collection is empty!");
        return;
    }

    clearFormUpdateCollection();

    _updateCollection->question1();

    QString text = _updateCollection->toText();
    ui->tE_updateCollection->setText(text);
}


void MainWindow::question2() {
    if (!_updateCollection->validateEmptyCollection()) {
        showErrorMessage("Error Empty", "This collection is empty!");
        return;
    }

    clearFormResult();

    int sum = _updateCollection->question2();
    ui->lE_resultSum->setText(QString::number(sum));
}


void MainWindow::showOpenFileDialog() {
    _openFileDialog->open();
}


void MainWindow::showCloseFileDialog() {
    _closeFileDialog->open();
}


void MainWindow::setOpenFileName(QString fileName) {
    clear();

    _openFileName = fileName;
    ui->lE_fileName->setText(fileName);

    setCollections();
}


void MainWindow::saveNewFile(QString fileName) {
    _saveFileName = fileName;
    _openFileName = fileName;

    delete _currentCollection;
    _currentCollection = new Collection(_updateCollection);

    ui->lE_fileName->setText(fileName);

    QString text = _currentCollection->toText();
    ui->tE_currentCollection->setText(text);

    Collection::renderCollectionFile(text, fileName);
}


void MainWindow::setCollections() {
    _currentCollection->parseCollectionFile(_openFileName);
    _updateCollection->parseCollectionFile(_openFileName);

    QString text;
    text = _currentCollection->toText();

    ui->tE_currentCollection->setText(text);
    ui->tE_updateCollection->setText(text);
}


void MainWindow::showErrorMessage(QString title, QString text) {
    _message->setWindowModality(Qt::WindowModality::WindowModal);
    _message->setIcon(QMessageBox::Critical);
    _message->setWindowTitle(title);
    _message->setText(text);
    _message->show();
}



void MainWindow::clearOpenFileName() {
    _openFileName = "";
}


void MainWindow::clearSaveFileName() {
    _saveFileName = "";
}


void MainWindow::clearCurrentCollection() {
    _currentCollection->clear();
}


void MainWindow::clearUpdateCollection() {
    _updateCollection->clear();
}


void MainWindow::clearFormMetadata() {
    ui->sB_indexOfElem->setValue(0);
    ui->sB_valueOfElem->setValue(0);
}


void MainWindow::clearFormResult() {
    ui->lE_resultSum->setText("");
}


void MainWindow::clearFormPath() {
    ui->lE_fileName->setText("");
}


void MainWindow::clearFormCurrentCollection() {
    ui->tE_currentCollection->setText("");
}


void MainWindow::clearFormUpdateCollection() {
    ui->tE_updateCollection->setText("");
}


void MainWindow::clear() {
    clearOpenFileName();
    clearSaveFileName();
    clearCurrentCollection();
    clearUpdateCollection();

    clearFormMetadata();
    clearFormResult();
    clearFormPath();
    clearFormCurrentCollection();
    clearFormUpdateCollection();
}
