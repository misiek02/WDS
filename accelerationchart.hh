#ifndef ACCELERATIONCHART_HH
#define ACCELERATIONCHART_HH

#include <QObject>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>
#include <QTimer>
#include <QDateTime>

class AccelerationChart : public QObject {
    Q_OBJECT

public:
    AccelerationChart();
    QChartView *getChartView();

private slots:
    void updateData();

private:
    QChart *chart;
    QLineSeries *series;
    QLineSeries *series2;
    QDateTimeAxis *axisX;
    QValueAxis *axisY;
    QChartView *chartView;
    QTimer *timer;
    QDateTime startTime; // Declaration of startTime variable
};

#endif // ACCELERATIONCHART_HH
