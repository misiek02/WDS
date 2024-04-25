#ifndef SPEEDOMETER_HH
#define SPEEDOMETER_HH

#include <QWidget>
#include <QTimer>
#include <QSlider>
#include <QLabel>

/**
 * @brief The Speedometer class construct a widget for displaying speedometer
 * It builds slider to controll showing value
 *
 * Measure device displays a face with numbers indicating value [0 - 100], temporarily
 * there are slider to adjust that indications
 */

class Speedometer : public QWidget {
    Q_OBJECT
public:
    /**
     * @brief Speedometer builds a speed indicator widget
     * @param parent the parent widget
     */
    explicit Speedometer(QWidget *parent = nullptr);
    /**
     * @brief setSpeed setting speed value
     * @param speed value of the speed
     */
    void setSpeed(int speed);

private slots:
    /**
     * @brief updateNeedle update needle position depends on speed
     * 100 - max speed
     * 260 - needle range [degree]
     * 130 - needle position moved back 130 degrees
     */
    void updateNeedle();
    /**
     * @brief sliderValue transmits slider value to speedometer
     * @param value value of the slider
     */
    void sliderValue(int value);

protected:
    /**
     * @brief paintEvent overrides the paint event to draw the speedometer
     */
    void paintEvent(QPaintEvent *) override;

private:
    QTimer *m_timer;
    QSlider *m_speedSlider;
    int m_speed;
    double m_angle;
};

#endif // SPEEDOMETER_HH
