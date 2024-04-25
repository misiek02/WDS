#ifndef CANVAS_HH
#define CANVAS_HH

#include <QWidget>
#include "distancesensors.hh"
#include "gyroscope.hh"
#include "socket.hh"
#include "speedometer.hh"
#include "accelerometer.hh"
#include "init.hh"

class Canvas : public QWidget
{
    Q_OBJECT
public:
    /**
     * @brief Canvas
     * @param parent
     */
    explicit Canvas(QWidget *parent = nullptr);
signals:

public slots:
    /**
     * @brief exit function which turns off app
     */
    void exit();
};

#endif // CANVAS_HH
