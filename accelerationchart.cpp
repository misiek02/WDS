#include "AccelerationChart.hh"

AccelerationChart::AccelerationChart() {
    series = new QLineSeries();
    series->setColor(Qt::red);
    series->setName(tr("Acceleration in X axis"));

    series2 = new QLineSeries();
    series2->setColor(Qt::blue);
    series2->setName(tr("Acceleration in Y axis"));

    chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series2);
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setTitle(tr("Acceleration Data Plot"));

    axisX = new QDateTimeAxis;
    axisX->setFormat("HH:mm:ss.zzz");
    axisX->setTitleText(tr("Time [s]"));
    axisX->setRange(QDateTime::currentDateTime().addSecs(-10), QDateTime::currentDateTime());
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    series2->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");
    axisY->setTitleText(tr("Acceleration [G]"));
    axisY->setRange(-1.0f, 1.0f);
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series2->attachAxis(axisY);

    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setBackgroundBrush(QBrush(Qt::transparent));
}

QChartView* AccelerationChart::getChartView() {
    return chartView;
}

void AccelerationChart::updateData() {
    QDateTime currentTime = QDateTime::currentDateTime();

    double newValue1 = 20.0;
    series->append(currentTime.toMSecsSinceEpoch(), newValue1);

    double newValue2 = 30.0;
    series2->append(currentTime.toMSecsSinceEpoch(), newValue2);

    while (!series->points().isEmpty() && series->points().first().x() < currentTime.addSecs(-10).toMSecsSinceEpoch()) {
        series->remove(0);
    }

    while (!series2->points().isEmpty() && series2->points().first().x() < currentTime.addSecs(-10).toMSecsSinceEpoch()) {
        series2->remove(0);
    }

    axisX->setRange(currentTime.addSecs(-10), currentTime);
}

void AccelerationChart::setXValue(float value){
    if(value > 19.62)
        value = 19.62;
    if(value < -19.62)
        value = -19.62;
    QDateTime currentTime = QDateTime::currentDateTime();

    series->append(currentTime.toMSecsSinceEpoch(), value);

    while (!series->points().isEmpty() && series->points().first().x() < currentTime.addSecs(-10).toMSecsSinceEpoch()) {
        series->remove(0);
    }
    axisX->setRange(currentTime.addSecs(-10), currentTime);
}

void AccelerationChart::setYValue(float value){
    if(value > 19.62)
        value = 19.62;
    if(value < -19.62)
        value = -19.62;
    QDateTime currentTime = QDateTime::currentDateTime();
    series2->append(currentTime.toMSecsSinceEpoch(), value);

    while (!series2->points().isEmpty() && series2->points().first().x() < currentTime.addSecs(-10).toMSecsSinceEpoch()) {
        series2->remove(0);
    }

    axisX->setRange(currentTime.addSecs(-10), currentTime);
}
