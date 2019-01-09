#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "QCoreApplication"
#include "QSettings"
#include "QDebug"

#include "settingswindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainUI)
{
    ui->setupUi(this);
    ui->lpnStatus->setVisible(false);
    ui->skuStatus->setVisible(false);
}

MainWindow::~MainWindow()
{

}

void MainWindow::initSettings(){
    QCoreApplication::setOrganizationName("RetCo");
    QCoreApplication::setOrganizationDomain("retnuh.us");
    QCoreApplication::setApplicationName("LabelManager");

    QSettings settings;

    settings.beginGroup("MainSettings");

    if ( settings.allKeys().size() != 0 ) {

        if ( !settings.contains("serverAddress") ) {
            settings.setValue("serverAddress", "https://retnuh.us");
            qInfo() << "Config error! Using server address: https://retnuh.us\n";
        }

        if ( !settings.contains("labelPrefix") ) {
            settings.setValue("labelPrefix", "LPN_");
            qInfo() << "Config error! Using LPN prefix: LPN_\n";
        }

        if ( !settings.contains("salvageLabel") ) {
            settings.setValue("salvageLabel", "svsvsv");
            qInfo() << "Config error! Using salvage label: svsvsv\n";
        }

        if ( !settings.contains("localMode") ) {
            settings.setValue("localMode", false);
            qInfo() << "Config error! Using local mode: False\n";
        }
        qInfo() << "Configuration loaded.\n";
    } else {
        qInfo() << "Config not found, using default settings.\n";
        settings.setValue("serverAddress", "https://retnuh.us");
        settings.setValue("labelPrefix", "LPN_");
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("localMode", false);
    }

    settings.endGroup();

}

void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow s;
    s.exec();

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
