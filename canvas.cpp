#include "canvas.hh"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <Qt3DExtras/Qt3DWindow>
#include <Qt3DCore/QEntity>
#include <Qt3DExtras/QOrbitCameraController>
#include <Qt3DRender/QCamera>
#include <Qt3DRender/QPointLight>
#include <Qt3DCore/QTransform>
#include <QVector3D>
#include <QChartView>
#include "Model3D.hh"
#include "AccelerationChart.hh"
#include "speedometer.hh"
#include <QPushButton>
#include <QLabel>
#include <QMessageBox> // Include for QMessageBox

Canvas::Canvas(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QHBoxLayout *contentLayout = new QHBoxLayout();
    QVBoxLayout *leftLayout = new QVBoxLayout();
    QVBoxLayout *rightLayout = new QVBoxLayout();

    DistanceSensors *dist = new DistanceSensors(this);
    Speedometer *speed = new Speedometer(this);

    // Set size policies
    speed->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    dist->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    TcpServ *tcp = new TcpServ(this); // Adjust this according to your actual implementation

    connect(tcp, SIGNAL(valueSharpChanged(int)), dist, SLOT(setSharpValue(int)));
    connect(tcp, SIGNAL(valueTof1Changed(int)), dist, SLOT(setTof1Value(int)));
    connect(tcp, SIGNAL(valueTof2Changed(int)), dist, SLOT(setTof2Value(int)));
    connect(tcp, SIGNAL(valueXChanged(float)), dist, SLOT(setXValue(float)));
    connect(tcp, SIGNAL(valueYChanged(float)), dist, SLOT(setYValue(float)));
    connect(tcp, SIGNAL(valueAngleChanged(float)), dist, SLOT(setAngleValue(float)));
    connect(tcp, SIGNAL(valueSpeedChanged(float)), speed, SLOT(setSpeedValue(float)));

    leftLayout->addWidget(speed);
    leftLayout->addWidget(dist);

    QWidget *leftWidget = new QWidget(this);
    leftWidget->setLayout(leftLayout);
    leftWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    QWidget *container = QWidget::createWindowContainer(view);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();
    Model3D *model3D = new Model3D(rootEntity);

    Qt3DRender::QCamera *cameraEntity = view->camera();
    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f / 9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 50.0f));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);

    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform();
    lightTransform->setTranslation(QVector3D(10.0f, 10.0f, 10.0f));
    lightEntity->addComponent(lightTransform);

    view->setRootEntity(rootEntity);

    rightLayout->addWidget(container);

    AccelerationChart *accelerationChart = new AccelerationChart();
    QChartView *chartView = accelerationChart->getChartView();
    chartView->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    // SIGNAL AND SLOTS FOR A CHART
    connect(tcp, SIGNAL(accelerationXChanged(float)), accelerationChart, SLOT(setXValue(float)));
    connect(tcp, SIGNAL(accelerationYChanged(float)), accelerationChart, SLOT(setYValue(float)));

    rightLayout->addWidget(chartView);

    QWidget *rightWidget = new QWidget(this);
    rightWidget->setLayout(rightLayout);
    rightWidget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    contentLayout->addWidget(leftWidget, 1); // 50%
    contentLayout->addWidget(rightWidget, 1); // 50%

    mainLayout->addLayout(contentLayout);

    // Add connect/disconnect button and status indicator
    QHBoxLayout *bottomLayout = new QHBoxLayout();
    QPushButton *button = new QPushButton(tr("Start Server"), this);
    QLabel *circle = new QLabel(this);
    circle->setFixedSize(20, 20);
    circle->setStyleSheet("background-color: red; border-radius: 10px;");

    bottomLayout->addWidget(button);
    bottomLayout->addWidget(circle);
    mainLayout->addLayout(bottomLayout);


    connect(button, &QPushButton::clicked, [button, circle, tcp]() {
        if (!tcp->isActive()) {
            tcp->activateServer();

            QMessageBox::information(nullptr, tr("Server Status"), tr("Server Started."));
            button->setText(tr("Connect"));
            circle->setStyleSheet("background-color: green; border-radius: 10px;");

        } else {
            tcp->deactivateServer();

            QMessageBox::information(nullptr, tr("Server Status"), tr("Server Stopped."));
            button->setText(tr("Disconnect"));
            circle->setStyleSheet("background-color: red; border-radius: 10px;");
        }
    });

    this->setLayout(mainLayout);
}
