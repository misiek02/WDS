#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QMainWindow>
#include <QApplication>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QMessageBox>
#include <QDebug>
#include "canvas.hh"
#include "accelerationchart.hh"


/**
 * @file mainwindow.hh
 * @brief Definition of the MainWindow class
 *
 * This file contains the class definition for the main window of the application.
 */

namespace Ui {

class MainWindow;
}

/**
 * @brief The MainWindow class represents the main window of the application
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for MainWindow class
     * @param parent Pointer to parent widget, default is nullptr
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow class
     */
    ~MainWindow();

private:
    Ui::MainWindow *ui;

};

#endif // MAINWINDOW_HH
