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
#include <QTranslator>
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
     * @param parent - pointer to parent widget, default is nullptr
     */
    explicit MainWindow(QWidget *parent = nullptr);

    /**
     * @brief Destructor for MainWindow class
     */
    ~MainWindow();

private slots:
    /**
     * @brief on_actionEnglish_triggered triggered when clicked English
     */
    void on_actionEnglish_triggered();
    /**
     * @brief on_actionPolski_triggered triggered when clicked Polish
     */
    void on_actionPolski_triggered();

    void on_action_triggered();

private:
    Ui::MainWindow *ui;
    QTranslator translator;
    void retranslateUi();

};

#endif // MAINWINDOW_HH
