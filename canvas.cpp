#include "canvas.hh"



Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{


    //QWidget *gyro = new Gyroscope(this);
    QWidget *in = new init(this);
    QWidget *acc = new accelerometer(this);
    QWidget *dist = new DistanceSensors(this);
    QWidget *speed = new Speedometer(this);
    QPushButton *button = new QPushButton(tr("EXIT"),this);
    button->move(650, 510);
    connect(button, SIGNAL(clicked()),this,SLOT(exit()));
    speed->resize(300,300);

    // Socket *cTest = new Socket(this);
    // cTest->Connect();
}

void Canvas::exit()
{
    //cout << "exit app" << endl;
    static_cast<QWidget*>(parent())->close();
}
