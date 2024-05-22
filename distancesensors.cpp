#include "distancesensors.hh"
#include "ui_distancesensors.h"

DistanceSensors::DistanceSensors(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DistanceSensors)
{
    ui->setupUi(this);




}

DistanceSensors::~DistanceSensors()
{
    delete ui;
}

void DistanceSensors::setSharpValue(int value)
{

        ui->sharp_lcd->display(value);
        ui->sharp_bar->setValue(value);


}

void DistanceSensors::setTof1Value(int value)
{
    ui->tof1_bar->setValue(value);
    ui->tof1_lcd->display(value);
}

void DistanceSensors::setTof2Value(int value)
{
    ui->tof2_bar->setValue(value);
    ui->tof2_lcd->display(value);
}

void DistanceSensors::setMotor1Value(int value)
{
   // QString mes = QString::number(value);
    ui->encoder1_lcd->display(value);
}


