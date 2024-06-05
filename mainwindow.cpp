#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include "qpropertyanimation.h"
#include <QComboBox>
#include <QStackedWidget>
#include <QVBoxLayout>


/**
 * @brief MainWindow::MainWindow Konstruktor klasy MainWindow
 * @param parent Rodzicielski widget
 *
 * Funkcja inicjalizuje glowne okno, ustawia widok 3D i kanvas, oswietlenie czy punkt widzenia.
 */
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    //lang_ID = 0;
    ui->setupUi(this);
    this->setMinimumSize(800, 600);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *layout = new QHBoxLayout(centralWidget);

    Canvas *canvas = new Canvas(this);
    canvas->setMinimumSize(800, 600);

    Qt3DExtras::Qt3DWindow *view = new Qt3DExtras::Qt3DWindow();
    QWidget *container = QWidget::createWindowContainer(view);
    container->setMinimumSize(400, 300);

    Qt3DCore::QEntity *rootEntity = new Qt3DCore::QEntity();

    // Ustawienie modelu 3D
    Model3D *model3D = new Model3D(rootEntity);

    // Ustawienie kamery
    Qt3DRender::QCamera *cameraEntity = view->camera();
    cameraEntity->lens()->setPerspectiveProjection(45.0f, 16.0f/9.0f, 0.1f, 1000.0f);
    cameraEntity->setPosition(QVector3D(0, 0, 1000.0f));
    cameraEntity->setViewCenter(QVector3D(0, 0, 0));

    // Ustawienie kontrolera kamery
    Qt3DExtras::QOrbitCameraController *camController = new Qt3DExtras::QOrbitCameraController(rootEntity);
    camController->setCamera(cameraEntity);

    // Ustawienie oswietlenia
    Qt3DCore::QEntity *lightEntity = new Qt3DCore::QEntity(rootEntity);
    Qt3DRender::QPointLight *light = new Qt3DRender::QPointLight(lightEntity);
    light->setColor("white");
    light->setIntensity(1);
    lightEntity->addComponent(light);

    // Ustawienie transformacji dla pozycji swiatla
    Qt3DCore::QTransform *lightTransform = new Qt3DCore::QTransform();
    lightTransform->setTranslation(QVector3D(10.0f, 10.0f, 10.0f)); // Set light position
    lightEntity->addComponent(lightTransform);

    view->setRootEntity(rootEntity);

    layout->addWidget(canvas);
    layout->addWidget(container);

    setCentralWidget(centralWidget);

    //connect(langGroup, SIGNAL (triggered(QAction *)), this, SLOT (slotLanguageChanged(QAction *)));

    // QTimer *timer = new QTimer(this);
    // connect(timer, &QTimer::timeout, this, [=]() {
    //     // Move camera 1 unit in X and Y axes
    //     QVector3D newPosition = cameraEntity->position() + QVector3D(10.0f, 10.0f, 0.0f);
    //     cameraEntity->setPosition(newPosition);

    //     // Rotate camera 1 degree around Z axis
    //     QQuaternion currentRotation = cameraEntity->transform()->rotation();
    //     QQuaternion newRotation = QQuaternion::fromAxisAndAngle(0.0f, 0.0f, 10.0f, 10.0f) * currentRotation;
    //     cameraEntity->transform()->setRotation(newRotation);
    // });
    // timer->start(1000); // Trigger every 1000 milliseconds (1 second)
}



// // we create the menu entries dynamically, dependent on the existing translations.
// void MainWindow::createLanguageMenu(void) {
//     QActionGroup* langGroup = new QActionGroup(ui.menuLanguage);
//     langGroup->setExclusive(true);

//     connect(langGroup, SIGNAL (triggered(QAction *)), this, SLOT (slotLanguageChanged(QAction *)));

//     // format systems language
//     QString defaultLocale = QLocale::system().name(); // e.g. "de_DE"
//     defaultLocale.truncate(defaultLocale.lastIndexOf('_')); // e.g. "de"

//     m_langPath = QApplication::applicationDirPath();
//     m_langPath.append("/languages");
//     QDir dir(m_langPath);
//     QStringList fileNames = dir.entryList(QStringList("TranslationExample_*.qm"));

//     for (int i = 0; i < fileNames.size(); ++i) {
//         // get locale extracted by filename
//         QString locale;
//         locale = fileNames[i]; // "TranslationExample_de.qm"
//         locale.truncate(locale.lastIndexOf('.')); // "TranslationExample_de"
//         locale.remove(0, locale.lastIndexOf('_') + 1); // "de"

//         QString lang = QLocale::languageToString(QLocale(locale).language());
//         QIcon ico(QString("%1/%2.png").arg(m_langPath).arg(locale));

//         QAction *action = new QAction(ico, lang, this);
//         action->setCheckable(true);
//         action->setData(locale);

//         ui->menuLanguage->addAction(action);
//         langGroup->addAction(action);

//         // set default translators and language checked
//         if (defaultLocale == locale) {
//             action->setChecked(true);
//         }
//     }
// }
// void MainWindow::changeEvent(QEvent* event) {
//     if(0 != event) {
//         switch(event->type()) {
//         // this event is send if a translator is loaded
//         case QEvent::LanguageChange:
//             ui.retranslateUi(this);
//             break;

//             // this event is send, if the system, language changes
//         case QEvent::LocaleChange:
//         {
//             QString locale = QLocale::system().name();
//             locale.truncate(locale.lastIndexOf('_'));
//             loadLanguage(locale);
//         }
//         break;
//         }
//     }
//     QMainWindow::changeEvent(event);
// }



/**
 * @brief MainWindow::~MainWindow Destruktor klasy MainWindow
 *
 * Usuwa obiekt UI.
 */
MainWindow::~MainWindow()
{
    //delete ui;
}



