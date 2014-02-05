#include "mainwindow.h"

#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :

    QMainWindow(parent),

    ui(new Ui::MainWindow)

{

    ui->setupUi(this);

    this->setFixedSize(400, 200);

    bouton = new QPushButton("Find", this);

    layout = new QHBoxLayout;

    zone1  = new QTextEdit(this);

    zone2  = new QTextEdit(this);

    zone3  = new QTextEdit(this);

    erase  = new QPushButton("clear", this);

    msgBox = new QMessageBox(this);

    msgBox->setText("Erreur...");

    msgBox->setStandardButtons(QMessageBox::Ok);

    msgBox->setIcon(QMessageBox::Warning);

    msgBox->setWindowTitle("Erreur...");

    erase->setVisible(false);

    zone3->setReadOnly(true);

    layout->addWidget(bouton);

    layout->addWidget(zone1);

    layout->addWidget(zone2);

    layout->addWidget(zone3);



    const int w_bouton = 60;

    const int h_bouton = 20;

    const int w_zone = 80;

    const int h_zone = 25;





    bouton->setFixedSize(w_bouton, h_bouton);

    erase->setFixedSize(w_bouton, h_bouton);

    zone1->setFixedSize(w_zone, h_zone);

    zone2->setFixedSize(w_zone, h_zone);

    zone3->setFixedSize(w_zone, h_zone);



    bouton->move(220, 60);

    erase->move(220, 60);

    zone1->move(20, 60);

    zone2->move(120, 60);

    zone3->move(300, 60);



    connect(bouton, SIGNAL(clicked()), this, SLOT(task()));

    connect(erase, SIGNAL(clicked()), this, SLOT(task2()));

}


int pgcd(int p, int q)
{
    int r;
    while((p%q) != 0)
    {
        r = p % q;
        p = q;
        q = r;
    }
    return q;
}





void MainWindow::task()

{



    int x = 0;

    int y = 0;

    int z = 0;

    int t = 0;

    x = this->zone1->toPlainText().toInt();

    y = this->zone2->toPlainText().toInt();

    if(this->zone1->toPlainText().isEmpty() || this->zone2->toPlainText().isEmpty() || !this->zone1->toPlainText().data()->isNumber()

                                              || !this->zone2->toPlainText().data()->isNumber())

    {

        t = msgBox->exec();

        switch(t)

        {

            case (QMessageBox::Ok):

                msgBox->close();

                break;

        }

    }

    else

    {

       z = pgcd(x, y);

       this->zone3->setText(QString::number(z));

       this->erase->setVisible(true);

    }

}



void MainWindow::task2()

{

    this->zone1->setText("");

    this->zone2->setText("");

    this->zone3->setText("");

    this->erase->setVisible(false);

}



MainWindow::~MainWindow()

{

    delete ui;

}
