#include "accelerometer.hh"
#include "ui_accelerometer.h"

accelerometer::accelerometer(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::accelerometer)
{
    ui->setupUi(this);

    // QLineSeries *series = new QLineSeries();
    // series->append(0,16);
    // series->append(1,16);
    // series->append(2,15);
    // series->append(3,33);


    // QChart *chart = new QChart();
    // chart->legend();
    // chart->addSeries(series);
    // chart->createDefaultAxes();

    // QFont font;
    // font.setPixelSize(16);
    // chart->setTitleFont(font);
    // chart->setTitleBrush(Qt::black);
    // chart->setTitle("acceleration");

    // QPen pen(Qt::red);
    // pen.setWidth(8);
    // series->setPen(pen);

    // chart->setAnimationDuration(QChart::AllAnimations);

    // // auto *axisX = new QDateTimeAxis;
    // // axisX->setTickCount(10);
    // // axisX->setFormat("HH mm");

    // QCategoryAxis *axisX = new QCategoryAxis();
    // axisX->append("1",0);
    // axisX->append("2",1);
    // axisX->append("3",2);
    // axisX->append("4",3);
    // chart->setAxisX(axisX,series);

    // QChartView *chartView = new QChartView(chart);
    // chartView->setRenderHint(QPainter::Antialiasing);

    // QMainWindow widget;

    // widget.setCentralWidget(chartView);
    // widget.resize(400,300);
    // widget.show();


}

accelerometer::~accelerometer()
{
    delete ui;
}
