#ifndef SPEEDOMETER_HH
#define SPEEDOMETER_HH

#include <QWidget>
#include <QTimer>
#include <QSlider>
#include <QLabel>

class Speedometer : public QWidget {
    Q_OBJECT
public:
    explicit Speedometer(QWidget *parent = nullptr);
    void setSpeed(int speed);

private slots:
    void updateNeedle();
    void sliderValueChanged(int value);

protected:
    void paintEvent(QPaintEvent *) override;

private:
    QTimer *m_timer;
    QSlider *m_speedSlider;
    int m_speed;
    double m_angle;
};

#endif // SPEEDOMETER_HH
