#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"

#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QProcess>

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

    QSettings settings;

    settings.sync();
    settings.beginGroup("MainSettings");

    if ( settings.allKeys().size() != 0 ) {

        //settings.value("lpnMap").toMap().find(settings.value("currentPrefix").toString()).value().toInt()


        if ( !settings.contains("serverAddress") ) {
            settings.setValue("serverAddress", "https://retnuh.us");
            qInfo() << "Config error! Using server address: https://retnuh.us";
        }


        if ( !settings.contains("printerName") ) {
            settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
            qInfo() << "Config error! Using printer name: Zebra_Technologies_ZTC_ZP_500_";
        }

        if ( !settings.contains("printCommand") ) {
            settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");
            qInfo() << "Config error! Using print command: /usr/bin/print_label.sh $PRINTER_NAME";
        }

        if ( !settings.contains("lpnMap") ) {
            QVariantMap lpnMap; lpnMap.insert("LPN_", 1);
            settings.setValue("lpnMap", lpnMap);
            qInfo() << "Config error! Using LPN map: { \"LPN_\", 1 }";
        }

        if ( !settings.contains("currentPrefix") ) {
            settings.setValue("currentPrefix", settings.value("lpnMap").toMap().begin().key() );
            qInfo() << "Config error! Using currentPrefix:" << settings.value("lpnMap").toMap().begin().key();
        }

        if ( !settings.contains("lpnPadding") ) {
            settings.setValue("lpnPadding", 4);
            qInfo() << "Config error! Using LPN padding: 4";
        }

        if ( !settings.contains("salvageLabel") ) {
            settings.setValue("salvageLabel", "svsvsv");
            qInfo() << "Config error! Using salvage label: svsvsv";
        }

        if ( !settings.contains("remoteMode") ) {
            settings.setValue("remoteMode", false);
            qInfo() << "Config error! Using remote mode: false";
        }
        qInfo() << "Configuration loaded.\n";
    } else {
        qInfo() << "Config not found, using default settings.";
        settings.setValue("serverAddress", "https://retnuh.us");
        settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
        settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");

        QVariantMap lpnMap; lpnMap.insert("LPN_", 1);
        settings.setValue("lpnMap", lpnMap);
        settings.setValue("lpnPadding", 4);
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("remoteMode", false);
        settings.setValue("currentPrefix", "LPN_");
    }

    settings.endGroup();
    settings.sync();
}

void MainWindow::updateUi(){

    qInfo() << "Updating MainWindow UI...";

    QSettings settings;

    settings.sync();

    settings.beginGroup("MainSettings");

    if (settings.value("remoteMode").toBool() ){
        ui->fetchLPNButton->setEnabled(true);
        ui->fetchSKUButton->setEnabled(true);
        int currentLPN = getLPN(settings.value("currentPrefix").toString());
        QString lpnString = lpnPrefix(settings.value("currentPrefix").toString(), settings.value("lpnPadding").toInt(), currentLPN);
        lpnString.append(QString::number(currentLPN));
        ui->lpnLineEdit->setText(lpnString);
        ui->skuLineEdit->setPlaceholderText("Fetch to populate");
        // Remote server code here
    } else {
        ui->fetchLPNButton->setEnabled(false);
        ui->fetchSKUButton->setEnabled(false);
        QString lpnString = getFullLPN(settings.value("currentPrefix").toString());
        ui->skuLineEdit->setPlaceholderText("");
        ui->lpnLineEdit->setText(lpnString);
    }

    settings.endGroup();
}

int MainWindow::getLPN(QString prefix){
    QSettings settings;
    settings.sync();
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    qInfo() << "Finding prefix:" << prefix;
    int lpn = settings.value("MainSettings/lpnMap").toMap().find(prefix).value().toInt();
    qInfo() << "Returning LPN:" << QString("%1").arg(QString::number(lpn));
    return lpn;
}

QString MainWindow::getFullLPN(QString prefix){
    QSettings settings;
    settings.sync();
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    int currentLPN = getLPN(prefix);
    qInfo() << "Padding:" << QString("%1").arg(settings.value("MainSettings/lpnPadding").toInt());
    QString lpnString = lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), currentLPN);
    lpnString.append(QString::number(currentLPN));
    qInfo() << "Returning LPN string:" << lpnString;
    return lpnString;
}

QString MainWindow::lpnPrefix(QString prefix, int padding, int lpn){
    int digits = 0; do { lpn /= 10; digits++; } while (lpn != 0);
    for (int i = 0; i < padding - digits; i++){
        prefix.append("0");
    }
    return prefix;
}

void MainWindow::on_getLpnPrefix(QString prefix, int padding, int lpn){
    emit lpnPrefixReturn(lpnPrefix(prefix, padding, lpn));
}

int MainWindow::printLabel(QString command, QString label){
    QSettings settings;
    //if (settings.value("printCommand").toString() == ""
    QStringList commandList = command.split(" ");
    QString program = commandList.at(0);
    QStringList arguments;
    for (int i = 1; i < commandList.size(); i++){
        if (commandList.at(i) == "$PRINTER_NAME") arguments.push_back(settings.value("MainSettings/printerName").toString());
        //else if (commandList.at(i) == "$FULL_LPN") arguments.push_back(ui->lpnLineEdit->text());
        else arguments.push_back(commandList.at(i));
    }
    arguments.push_back(label);
    qInfo() << "Command: " << program << arguments;
    QProcess *printProcess = new QProcess(this);
    return printProcess->execute(program, arguments);
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

void MainWindow::on_printLPNButton_released()
{
    QSettings settings;
    QString prefix = settings.value("MainSettings/currentPrefix").toString();
    QString lpnString = getFullLPN();

    int status = printLabel(settings.value("MainSettings/printCommand").toString(), lpnString);
    qInfo() << "Status:" << QString("%1").arg(QString::number(status));
    if (status == 0){
        QVariantMap lpnMap = settings.value("MainSettings/lpnMap").toMap();
        lpnMap.remove(prefix);
        lpnMap.insert(prefix, getLPN(prefix)+1);
        settings.setValue("MainSettings/lpnMap", lpnMap);
        settings.sync();
        updateUi();
    }
}

void MainWindow::on_printSKUButton_released()
{
    QSettings settings;
    printLabel(settings.value("MainSettings/printCommand").toString(), ui->skuLineEdit->text());
}

void MainWindow::on_printTextButton_released()
{
    QSettings settings;
    printLabel(settings.value("MainSettings/printCommand").toString(), ui->textLineEdit->text());
}

void MainWindow::on_printSalvageButton_released()
{
    QSettings settings;
    printLabel(settings.value("MainSettings/printCommand").toString(), settings.value("MainSettings/salvageLabel").toString());
}
