#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{


    ui->setupUi(this);
    Canvas *c = new Canvas(this);
    setCentralWidget(c);

    // // this->setMinimumSize(1480, 910);

}

MainWindow::~MainWindow()
{
    delete ui;
}
