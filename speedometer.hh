#ifndef SPEEDOMETER_HH
#define SPEEDOMETER_HH

#include <QWidget>
#include <QTimer>
#include <QSlider>
#include <QLabel>

/**
 * @file speedometer.hh
 * @brief Definition of the Speedometer class
 *
 * This file contains the class definition.
 */


/**
 * @brief Models the concept of a speedometer
 */
class Speedometer : public QWidget {
    Q_OBJECT
public:
    explicit Speedometer(QWidget *parent = nullptr);
    /**
     * @brief setSpeed sets the speed
     * @param speed speed parameter
     */
    void setSpeed(int speed);

private slots:
    /**
     * @brief updateNeedle refreshes the position of the clock's needle
     */
    void updateNeedle();
    /**
     * @brief sliderValueChanged handles the slider's value change
     * @param value slider's value
     */
    void sliderValueChanged(int value);

protected:
    /**
     * @brief paintEvent allows for the creation of the speedometer clock object
     */
    void paintEvent(QPaintEvent *) override;

private:
    QTimer *m_timer;
    QSlider *m_speedSlider;
    int m_speed;
    double m_angle;
};

#endif // SPEEDOMETER_HH
