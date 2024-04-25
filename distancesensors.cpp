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
