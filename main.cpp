#include "canvas.hh"
#include "mainwindow.hh"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    w.setWindowTitle(QObject::tr("TYGRYSICA"));
    return a.exec();
}
