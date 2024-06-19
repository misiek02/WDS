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
public slots:
    /**
     * @brief Sets the acceleration in X axis
     * @param value - acceleration in X axis
     */
    void setXValue(float value);

    /**
     * @brief Sets the acceleration in Y axis
     * @param value - acceleration in Y axis
     */
    void setYValue(float value);


private:
    QChart *chart; /**< Chart object variable*/
    QLineSeries *series;/**< First line on graph variable*/
    QLineSeries *series2;/**< Second line on graph variable*/
    QDateTimeAxis *axisX;/**< Vertical axis variable*/
    QValueAxis *axisY;/**< Horisontal axis variable*/
    QChartView *chartView;/**< Chart display variable*/
    QTimer *timer;/**< Time variable*/
    QDateTime startTime; //**< Declaration of startTime variable*/
};

#endif // ACCELERATIONCHART_HH
