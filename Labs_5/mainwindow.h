#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QMessageBox>

#include <collections/collection.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void showElementOfIndex();

    void removeElemOfIndex();

    void removeElemOfValue();

    void addElement();

    void calculateSumOfElements();

    void calculateSumOfEvenElements();

    void question1();

    void question2();

    void showOpenFileDialog();

    void showCloseFileDialog();

    void setOpenFileName(QString fileName);

    void saveNewFile(QString fileName);

private:
    void setCollections();

    void showErrorMessage(QString title, QString text);


    void clearOpenFileName();

    void clearSaveFileName();

    void clearCurrentCollection();

    void clearUpdateCollection();


    void clearFormMetadata();

    void clearFormResult();

    void clearFormPath();

    void clearFormCurrentCollection();

    void clearFormUpdateCollection();

    void clear();

private:
    Ui::MainWindow *ui;

    QFileDialog *_openFileDialog;
    QFileDialog *_closeFileDialog;

    QMessageBox *_message;

    QString _openFileName;
    QString _saveFileName;

    Collection *_currentCollection;
    Collection *_updateCollection;
};
#endif // MAINWINDOW_H
