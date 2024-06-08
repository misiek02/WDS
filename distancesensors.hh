#ifndef DISTANCESENSORS_HH
#define DISTANCESENSORS_HH

#include "tcpserv.hh"
#include <QWidget>

/**
 * @file distancesensors.hh
 * @brief Definition of the DistanceSensors class
 *
 * This file contains the class definition.
 */

namespace Ui {
class DistanceSensors;
}

/**
 * @file distancesensors.hh
 * @brief Definition of the DistanceSensors class
 *
 * This file contains the class definition.
 */

/**
 * @brief Models the concept of distance sensors
 */
class DistanceSensors : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief Constructs a DistanceSensors object
     * @param parent the parent widget
     */
    explicit DistanceSensors(QWidget *parent = nullptr);
    /**
     * @brief Destroys the DistanceSensors object
     */
    ~DistanceSensors();

public slots:
    /**
     * @brief Sets the Sharp sensor value
     * @param value the sensor value
     */
    void setSharpValue(int value);
    /**
     * @brief Sets the ToF1 sensor value
     * @param value the sensor value
     */
    void setTof1Value(int value);
    /**
     * @brief Sets the ToF2 sensor value
     * @param value the sensor value
     */
    void setTof2Value(int value);
    /**
     * @brief Sets the X coordinate value
     * @param value the X coordinate value
     */
    void setXValue(float value);
    /**
     * @brief Sets the Y coordinate value
     * @param value the Y coordinate value
     */
    void setYValue(float value);
    /**
     * @brief Sets the angle value
     * @param value the angle value
     */
    void setAngleValue(float value);
    // void sendCoordinates(float x, float y, TcpServ *t);

signals:
    /**
     * @brief Emitted when a sensor value changes
     * @param newValue the new sensor value
     */
    void valueChanged(int newValue);

private:
    Ui::DistanceSensors *ui;
};

#endif // DISTANCESENSORS_HH
