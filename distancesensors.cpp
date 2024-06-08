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

void DistanceSensors::setXValue(float value)
{
    QString mes = QString::number(value, 'f', 2);
    ui->x_val->display(mes);
}

void DistanceSensors::setYValue(float value)
{
    QString mes = QString::number(value, 'f', 2);
    ui->y_val->display(mes);
}

void DistanceSensors::setAngleValue(float value)
{
    QString mes = QString::number(value, 'f', 2);
    ui->angle_val->display(mes);
}

// void DistanceSensors::sendCoordinates(float x, float y, TcpServ *t)
// {
//     float x = ui->x_val->value();
//     float y = ui->y_val->value();

//     QByteArray data = QString("X:%1 Y:%2").arg(x).arg(y).toUtf8();
//     t->broadcastData(data);
// }



