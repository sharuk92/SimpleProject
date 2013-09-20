#ifndef MAINWINDOW_H

#define MAINWINDOW_H



#include <QMainWindow>

#include <QPushButton>

#include <QTextEdit>

#include <QLayout>

#include <QMessageBox>

#include <string>



namespace Ui {

class MainWindow;

}



class MainWindow : public QMainWindow

{

    Q_OBJECT



public:

    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    

private:

    Ui::MainWindow *ui;

    QPushButton* bouton;

    QTextEdit* zone1;

    QTextEdit* zone2;

    QTextEdit* zone3;

    QPushButton* erase;

    QMessageBox* msgBox;

    QHBoxLayout* layout;

public slots:

    void task();

    void task2();

};



int divide(int &m, int &n, int &r);



int find_divisor(int &m, int &n);



#endif // MAINWINDOW_H
