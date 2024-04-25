#ifndef ACCELEROMETER_HH
#define ACCELEROMETER_HH

#include <QWidget>
#include <QGraphicsWidget>
#include <QtCharts>
#include <QLineSeries>
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>
namespace Ui {
class accelerometer;
}

class accelerometer : public QWidget
{
    Q_OBJECT

public:
    explicit accelerometer(QWidget *parent = nullptr);
    ~accelerometer();

private:
    Ui::accelerometer *ui;
};

#endif // ACCELEROMETER_HH
