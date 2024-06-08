#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setMinimumSize(800, 600);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    Canvas *canvas = new Canvas(this);
    canvas->setMinimumSize(800, 600);

    QWidget *rightWidget = new QWidget(this);
    QVBoxLayout *rightLayout = new QVBoxLayout(rightWidget);

    // Set up the 3D view
    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    QWidget *container = QWidget::createWindowContainer(view);
    container->setMinimumSize(400, 300);

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Set up the 3D model
    Model3D *model3D = new Model3D(rootEntity);

    // Set up the camera
    Qt3DRender::QCamera *cameraEntity = view->camera();
    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 500.0f));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // Set up camera controls
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Set up light
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);

    // Set up transform for light position
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform();
    lightTransform->setTranslation(QVector3D(10.0f, 10.0f, 10.0f)); // Set light position
    lightEntity->addComponent(lightTransform);

    view->setRootEntity(rootEntity);

    // Set up the chart
    AccelerationChart *accelerationChart = new AccelerationChart();
    QChartView *chartView = accelerationChart->getChartView();
    chartView->setMinimumSize(400, 300);

    rightLayout->addWidget(container);
    rightLayout->addWidget(chartView);

    mainLayout->addWidget(canvas);
    mainLayout->addWidget(rightWidget);

    setCentralWidget(centralWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
