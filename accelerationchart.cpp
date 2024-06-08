#include "AccelerationChart.hh"

AccelerationChart::AccelerationChart() {
    // Initialize the series and chart
    series = new QLineSeries();
    series->setColor(Qt::red); // Set the line color to red

    series2 = new QLineSeries();
    series2->setColor(Qt::blue); // Set the line color to blue

    chart = new QChart();
    chart->addSeries(series);
    chart->addSeries(series2);
    // chart->legend()->hide();
    chart->setTitle("Acceleration Data Plot");

    // Set up axes
    axisX = new QDateTimeAxis;
    axisX->setFormat("HH:mm:ss.zzz");  // Set time format with milliseconds
    axisX->setTitleText("Time");
    axisX->setRange(QDateTime::currentDateTime().addSecs(-10), QDateTime::currentDateTime());  // 10 second range
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);
    series2->attachAxis(axisX);

    axisY = new QValueAxis;
    axisY->setLabelFormat("%.1f");
    axisY->setTitleText("Value");
    axisY->setRange(0, 100); // Example range, adjust as needed
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);
    series2->attachAxis(axisY);

    // Set up the chart view
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);

    // Set up a timer for updating the data
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &AccelerationChart::updateData);
    timer->start(100); // Update every 0.1 seconds
}

QChartView* AccelerationChart::getChartView() {
    return chartView;
}

void AccelerationChart::updateData() {
    QDateTime currentTime = QDateTime::currentDateTime();  // Use current date and time with milliseconds

    // Generate a new data point for the first series (simulate some data)
    double newValue1 = rand() % 100;
    series->append(currentTime.toMSecsSinceEpoch(), newValue1);

    // Generate a new data point for the second series (simulate some data)
    double newValue2 = rand() % 100;
    series2->append(currentTime.toMSecsSinceEpoch(), newValue2);

    // Remove points that are out of the visible range for the first series
    while (!series->points().isEmpty() && series->points().first().x() < currentTime.addSecs(-10).toMSecsSinceEpoch()) {
        series->remove(0);
    }

    // Remove points that are out of the visible range for the second series
    while (!series2->points().isEmpty() && series2->points().first().x() < currentTime.addSecs(-10).toMSecsSinceEpoch()) {
        series2->remove(0);
    }

    // Update the X axis range to keep it moving
    axisX->setRange(currentTime.addSecs(-10), currentTime);
}
