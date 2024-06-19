#include "mainwindow.hh"
#include "ui_mainwindow.h"
#include <QHBoxLayout>
#include <QVBoxLayout>
#include "canvas.hh"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setMinimumSize(800, 775);

    QWidget *centralWidget = new QWidget(this);
    QHBoxLayout *mainLayout = new QHBoxLayout(centralWidget);

    Canvas *canvas = new Canvas(this);
    canvas->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    mainLayout->addWidget(canvas);
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);
}


MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::retranslateUi(){
    ui->retranslateUi(this);
}


void MainWindow::on_actionEnglish_triggered()
{
    qApp->removeTranslator(&translator);
    retranslateUi();
    QMessageBox::information(this,tr("Language"), tr("Language changed"), QMessageBox::Ok);
}


void MainWindow::on_actionPolski_triggered()
{
    if(translator.load(":/i18n/translation_pl.ts")){
        qApp->installTranslator(&translator);
        retranslateUi();
        QMessageBox::information(this,tr("Język"), tr("Zmieniono język"), QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("Język"), tr("Blad"), QMessageBox::Ok);
    }
}


void MainWindow::on_action_triggered()
{
    if(translator.load(":/i18n/translation_jp.ts")){
        qApp->installTranslator(&translator);
        retranslateUi();
        QMessageBox::information(this,tr("言語"), tr("言語が変更されました"), QMessageBox::Ok);
    }
    else{
        QMessageBox::information(this,tr("言語"), tr("間違い"), QMessageBox::Ok);
    }
}

