#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settingswindow.h"

#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QProcess>
#include <QClipboard>
#include <QMessageBox>

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

        if ( !settings.contains("serverAddress") ) {
            settings.setValue("serverAddress", "https://retnuh.us");
            qInfo() << "Config error! Using server address: https://retnuh.us";
        }

        if ( !settings.contains("skuServer") ) {
            settings.setValue("skuServer", false);
            qInfo() << "Config error! Using SKU server: false";
        }

        if ( !settings.contains("skuServerAddress") ) {
            settings.setValue("skuServerAddress", "http://skufindnr.retnuh.us");
            qInfo() << "Config error! Using SKU server address: http://skufindnr.retnuh.us";
        }

        if ( !settings.contains("printServer") ) {
            settings.setValue("printServer", "localhost");
            qInfo() << "Config error! Using print server: localhost";
        }

        if ( !settings.contains("printerName") ) {
            settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
            qInfo() << "Config error! Using printer name: Zebra_Technologies_ZTC_ZP_500_";
        }

        if ( !settings.contains("printCommand") ) {
            settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");
            qInfo() << "Config error! Using print command: /usr/bin/print_label.sh $PRINTER_NAME";
        }

        if ( !settings.contains("usePrintCommand") ) {
            settings.setValue("usePrintCommand", true);
            qInfo() << "Config error! Using print command enabled: true";
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

        if ( !settings.contains("copyClipboard") ) {
            settings.setValue("copyClipboard", true);
            qInfo() << "Config error! Using copy to clipboard: true";
        }

        qInfo() << "Configuration loaded.\n";
    } else {
        qInfo() << "Config not found, using default settings.";
        settings.setValue("serverAddress", "https://retnuh.us");
        settings.setValue("skuServer", false);
        settings.setValue("skuServerAddress", "http://skufindnr.retnuh.us");
        settings.setValue("printServer", "localhost");
        settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
        settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");
        settings.setValue("usePrintCommand", true);

        QVariantMap lpnMap; lpnMap.insert("LPN_", 1);
        settings.setValue("lpnMap", lpnMap);
        settings.setValue("lpnPadding", 4);
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("remoteMode", false);
        settings.setValue("currentPrefix", "LPN_");
        settings.setValue("copyClipboard", true);
    }

    settings.endGroup();

    settings.beginGroup("UI");

    if ( settings.allKeys().size() != 0 ) {
        if ( !settings.contains("printQuantity") ) {
            QVariantList printQuantity = {1, 1, 1};
            settings.setValue("printQuantity", printQuantity);
            qInfo() << "Config error! Using printQuantity: {1, 1, 1}";
        }
    } else {
        QVariantList printQuantity = {1, 1, 1};
        settings.setValue("printQuantity", printQuantity);
    }

    // Watch settings file for changes
    settingsWatcher.addPath(settings.fileName());
    connect(&settingsWatcher, SIGNAL(fileChanged(const QString)), this, SLOT(on_settingsChange(const QString)));

    //settings.sync();
}

void MainWindow::on_settingsChange(const QString sFile){
    qInfo() << "Settings file changed, updating..";
    // Watch file again in case file has been updated by being replaced
    settingsWatcher.addPath(sFile);
    updateUi();
}

void MainWindow::updateUi(){

    QSettings settings;

    settings.sync();

    settings.beginGroup("MainSettings");

    if (settings.value("remoteMode").toBool() ){
        //ui->fetchLPNButton->setEnabled(true);
        ui->fetchSKUButton->setEnabled(true);
        ui->skuLineEdit->setPlaceholderText("Fetch to populate");
        // Remote server code here
    } else {
        //ui->fetchLPNButton->setEnabled(false);
        ui->fetchSKUButton->setEnabled(false);
        ui->skuLineEdit->setPlaceholderText("");
    }

    QString lpnString = getFullLPN(settings.value("currentPrefix").toString());
    ui->lpnLineEdit->setText(lpnString);

    settings.endGroup();

    settings.beginGroup("UI");
    ui->lpnQuantitySpinBox->setValue( settings.value("printQuantity").toList().at(0).toInt() );
    ui->skuQuantitySpinBox->setValue( settings.value("printQuantity").toList().at(1).toInt() );
    ui->textQuantitySpinBox->setValue( settings.value("printQuantity").toList().at(2).toInt() );
    settings.endGroup();
}

int MainWindow::getLPN(QString prefix){
    QSettings settings;
    settings.sync();
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    //qInfo() << "Finding prefix:" << prefix;
    int lpn = settings.value("MainSettings/lpnMap").toMap().find(prefix).value().toInt();
    //qInfo() << "Returning LPN:" << QString("%1").arg(QString::number(lpn));
    return lpn;
}

QString MainWindow::getFullLPN(QString prefix){
    QSettings settings;
    settings.sync();
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    int currentLPN = getLPN(prefix);
    //qInfo() << "Padding:" << QString("%1").arg(settings.value("MainSettings/lpnPadding").toInt());
    QString lpnString = lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), currentLPN);
    lpnString.append(QString::number(currentLPN));
    //qInfo() << "Returning LPN string:" << lpnString;
    return lpnString;
}

QString MainWindow::lpnPrefix(QString prefix, int padding, int lpn){
    int digits = 0; do { lpn /= 10; digits++; } while (lpn != 0);
    for (int i = 0; i < padding - digits; i++){
        prefix.append("0");
    }
    return prefix;
}

int MainWindow::printLabel(QString command, QString label){
    QSettings settings;
    if (settings.value("MainSettings/usePrintCommand").toBool() == false) {
        return -9;
    } else {
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
}

void MainWindow::on_actionSettings_triggered()
{
    SettingsWindow s;
    s.setFixedHeight(225);
    //s.setFixedWidth(415);
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
    ui->printLPNButton->setEnabled(false);
    QSettings settings;
    QClipboard *clipboard = QApplication::clipboard();
    QString prefix = settings.value("MainSettings/currentPrefix").toString();
    QString lpnString = getFullLPN();
    int status = 0;
    for (int i = 0; i < ui->lpnQuantitySpinBox->value(); i++){
        status = printLabel(settings.value("MainSettings/printCommand").toString(), lpnString);
        if ( status != 0 ) break;
    }
    qInfo() << "Status:" << QString("%1").arg(QString::number(status));
    if (status == 0){
        if (settings.value("MainSettings/copyClipboard").toBool()) clipboard->setText(lpnString);
        QVariantMap lpnMap = settings.value("MainSettings/lpnMap").toMap();
        lpnMap.remove(prefix);
        lpnMap.insert(prefix, getLPN(prefix)+1);
        settings.setValue("MainSettings/lpnMap", lpnMap);
        //settings.sync();
        updateUi();
    } else {
        QMessageBox msgBox;
        msgBox.setWindowTitle("Error!");
        msgBox.setText("Print failed: Errno " + QString::number(status));
        msgBox.setModal(true);
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    ui->printLPNButton->setEnabled(true);
}

void MainWindow::on_printSKUButton_released()
{
    ui->printSKUButton->setEnabled(false);
    QSettings settings;
    for (int i = 0; i < ui->skuQuantitySpinBox->value(); i++){
        printLabel(settings.value("MainSettings/printCommand").toString(), ui->skuLineEdit->text());
    }
    ui->printSKUButton->setEnabled(true);
}

void MainWindow::on_printTextButton_released()
{
    ui->printTextButton->setEnabled(false);
    QSettings settings;
    for (int i = 0; i < ui->textQuantitySpinBox->value(); i++){
        printLabel(settings.value("MainSettings/printCommand").toString(), ui->textLineEdit->text());
    }
    ui->printTextButton->setEnabled(true);
}

void MainWindow::on_printSalvageButton_released()
{
    ui->printSalvageButton->setEnabled(false);
    QSettings settings;
    printLabel(settings.value("MainSettings/printCommand").toString(), settings.value("MainSettings/salvageLabel").toString());
    ui->printSalvageButton->setEnabled(true);
}

void MainWindow::on_lpnQuantitySpinBox_valueChanged(int qty)
{
    QSettings settings;
    QVariantList printQuantity = settings.value("UI/printQuantity").toList();
    printQuantity.replace(0, qty);
    settings.setValue("UI/printQuantity", printQuantity);
}

void MainWindow::on_skuQuantitySpinBox_valueChanged(int qty)
{
    QSettings settings;
    QVariantList printQuantity = settings.value("UI/printQuantity").toList();
    printQuantity.replace(1, qty);
    settings.setValue("UI/printQuantity", printQuantity);
}

void MainWindow::on_textQuantitySpinBox_valueChanged(int qty)
{
    QSettings settings;
    QVariantList printQuantity = settings.value("UI/printQuantity").toList();
    printQuantity.replace(2, qty);
    settings.setValue("UI/printQuantity", printQuantity);
}

void MainWindow::on_reprintLPNButton_released()
{
    QSettings settings;
    QString prefix = settings.value("MainSettings/currentPrefix").toString();
    int prevLPN = getLPN(prefix)-1;
    QString lpnString = lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), prevLPN);
    lpnString.append(QString::number(prevLPN));
    ui->reprintLPNButton->setEnabled(false);
    for (int i = 0; i < ui->lpnQuantitySpinBox->value(); i++){
        printLabel(settings.value("MainSettings/printCommand").toString(), lpnString);
    }
    ui->reprintLPNButton->setEnabled(true);
}
