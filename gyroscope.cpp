#include "gyroscope.hh"
#include "ui_gyroscope.h"

Gyroscope::Gyroscope(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Gyroscope)
{
    ui->setupUi(this);



}

Gyroscope::~Gyroscope()
{
    delete ui;
}
