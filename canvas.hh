#ifndef CANVAS_HH
#define CANVAS_HH

#include <QWidget>
#include "distancesensors.hh"
#include "gyroscope.hh"
#include "speedometer.hh"
#include "tcpserv.hh"
#include "model3d.hh"


class Canvas : public QWidget
{
    Q_OBJECT
public:
    explicit Canvas(QWidget *parent = nullptr);
signals:
};

#endif // CANVAS_HH
