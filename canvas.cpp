#include "canvas.hh"



Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{


    DistanceSensors *dist = new DistanceSensors(this);
    QWidget *speed = new Speedometer(this);
    speed->resize(300,300);
    TcpServ *tcp = new TcpServ(this);

    connect(tcp, SIGNAL(valueSharpChanged(int)), dist, SLOT(setSharpValue(int)));
    connect(tcp, SIGNAL(valueTof1Changed(int)), dist, SLOT(setTof1Value(int)));
    connect(tcp, SIGNAL(valueTof2Changed(int)), dist, SLOT(setTof2Value(int)));
    connect(tcp, SIGNAL(valueXChanged(float)), dist, SLOT(setXValue(float)));
    connect(tcp, SIGNAL(valueYChanged(float)), dist, SLOT(setYValue(float)));
    connect(tcp, SIGNAL(valueAngleChanged(float)), dist, SLOT(setAngleValue(float)));


    this->setMinimumSize(800, 600);

    // Socket *cTest = new Socket(this);
    // cTest->Connect();
}

