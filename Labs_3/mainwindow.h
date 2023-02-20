#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void changeComboBox(int index);

    int getMaterialCost(int index);

    void calculate();

private:
    Ui::MainWindow *ui;

    int _comboBoxIndex;
};
#endif // MAINWINDOW_H
