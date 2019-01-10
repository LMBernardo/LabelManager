#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"

#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

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
    delete ui;
}

void MainWindow::initSettings(){

    QCoreApplication::setOrganizationName("retco");
    QCoreApplication::setOrganizationDomain("retnuh.us");
    QCoreApplication::setApplicationName("LabelManager");
    QSettings settings;

    settings.beginGroup("MainSettings");

    if ( settings.allKeys().size() != 0 ) {

        //settings.value("lpnMap").toMap().find(settings.value("currentPrefix").toString()).value().toInt()


        if ( !settings.contains("serverAddress") ) {
            settings.setValue("serverAddress", "https://retnuh.us");
            qInfo() << "Config error! Using server address: https://retnuh.us\n";
        }

        if ( !settings.contains("lpnMap") ) {
            QVariantMap lpnMap; lpnMap.insert("LPN_", 0);
            settings.setValue("lpnMap", lpnMap);
            qInfo() << "Config error! Using LPN map: { \"LPN_\", 0 }\n";
        }

        if ( !settings.contains("currentPrefix") ) {
            settings.setValue("currentPrefix", settings.value("lpnMap").toMap().begin().key() );
            qInfo() << "Config error! Using currentPrefix:" << settings.value("lpnMap").toMap().begin().key();
        }

        if ( !settings.contains("currentLPN")){
            if (!settings.value("remoteMode").toBool()) {
                settings.setValue("currentLPN", 0);
                qInfo() << "Config error! currentLPN not found, using 0";
            }
        }

        if ( !settings.contains("lpnPadding") ) {
            settings.setValue("lpnPadding", 4);
            qInfo() << "Config error! Using LPN padding: 4\n";
        }

        if ( !settings.contains("salvageLabel") ) {
            settings.setValue("salvageLabel", "svsvsv");
            qInfo() << "Config error! Using salvage label: svsvsv\n";
        }

        if ( !settings.contains("remoteMode") ) {
            settings.setValue("remoteMode", false);
            qInfo() << "Config error! Using remote mode: false\n";
        }
        qInfo() << "Configuration loaded.\n";
    } else {
        qInfo() << "Config not found, using default settings.\n";
        settings.setValue("serverAddress", "https://retnuh.us");
        QVariantMap lpnMap; lpnMap.insert("LPN_", 0);
        settings.setValue("lpnMap", lpnMap);
        settings.setValue("lpnPadding", 4);
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("remoteMode", false);
        settings.setValue("currentPrefix", "LPN_");
    }

    settings.endGroup();
}

void MainWindow::updateUi(){

    QCoreApplication::setOrganizationName("retco");
    QCoreApplication::setOrganizationDomain("retnuh.us");
    QCoreApplication::setApplicationName("LabelManager");
    QSettings settings;

    settings.beginGroup("MainSettings");

    if (settings.value("remoteMode").toBool() ){
        ui->fetchLPNButton->setEnabled(true);
        ui->fetchSKUButton->setEnabled(true);
        ui->lpnSpinBox->setValue(settings.value("lpnMap").toMap().find(settings.value("currentPrefix").toString()).value().toInt());
        // Remote server code here
    } else {
        ui->fetchLPNButton->setEnabled(false);
        ui->fetchSKUButton->setEnabled(false);
        int currentLPN = settings.value("lpnMap").toMap().find(settings.value("currentPrefix").toString()).value().toInt();
        QString lpnString = lpnPrefix(settings.value("currentPrefix").toString(), settings.value("lpnPadding").toInt(), currentLPN);
        ui->lpnLineEdit->setText(lpnString);
    }

    settings.endGroup();
}

QString MainWindow::lpnPrefix(QString prefix, int padding, int lpn){
    int digits = 0; do { lpn /= 10; digits++; } while (lpn != 0);
    for (int i = 0; i < padding+1 - digits; i++){
        prefix.append("0");
    }
    return prefix;
}

void MainWindow::on_getLpnPrefix(QString prefix, int padding, int lpn){
    emit lpnPrefixReturn(lpnPrefix(prefix, padding, lpn));
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow s;
    connect(&s, SIGNAL(getLpnPrefix(QString, int, int)), this, SLOT(on_getLpnPrefix(QString, int, int)));
    connect(this, SIGNAL(lpnPrefixReturn(QString)), &s, SLOT(on_lpnPrefixReturn(QString)));
    s.initSettings();
    s.exec();
    updateUi();

}

void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}
