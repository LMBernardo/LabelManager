#include "getstringdialog.h"
#include "settingswindow.h"
#include "ui_settingswindow.h"
#include "utils.h"

#include <QCoreApplication>
#include <QSettings>
#include <QMessageBox>

#include <QDebug>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsUI)
{
    ui->setupUi(this);

    ui->remoteLabel->setVisible(false);
    ui->remoteLineEdit->setVisible(false);
    ui->remoteSyncButton->setVisible(false);
    ui->remoteCheckbox->setVisible(false);
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::initSettingsWindow(){
    readSettings();
    init = true;

    // Select proper tab
    ui->tabWidget->setCurrentIndex(0);

    // Only accept numbers and letters in printer name
    //ui->printerNameLineEdit->setValidator( new QRegExpValidator(QRegExp("[0-9][a-zA-Z]")) );
}

void SettingsWindow::saveSettings(){

    qInfo() << "Saving settings...";

    QSettings settings;

    settings.sync();

    settings.beginGroup("MainSettings");

    settings.setValue("serverAddress", ui->remoteLineEdit->text());
    //settings.setValue("skuServerAddress", ui->skuServerLineEdit->text());
    settings.setValue("skuServer", ui->skuServerCheckbox->isChecked());
    settings.setValue("printServer", ui->printServerLineEdit->text());
    settings.setValue("printerName", ui->printerNameLineEdit->text());
    settings.setValue("printCommand", ui->printCommandLineEdit->text());
    settings.setValue("usePrintCommand", ui->printCommandCheckbox->isChecked());

    settings.setValue("startMinimized", ui->startMinimizedCheckbox->isChecked());
    settings.setValue("enableSystemTrayIcon", ui->enableSysTrayCheckbox->isChecked());
    settings.setValue("minimizeToSystemTray", ui->minimizeToSysTrayCheckbox->isChecked());
    settings.setValue("systemTrayNotifications", ui->sysTrayNotificationsCheckbox->isChecked());

    QVariantMap lpnMap;
    for (int i = 0; i < ui->prefixComboBox->count(); i++){
        qDebug() << "Prefix iterated:" << ui->prefixComboBox->itemText(i);
        lpnMap.insert(ui->prefixComboBox->itemText(i), Utils::getLPN(ui->prefixComboBox->itemText(i)));
    }
    settings.setValue("lpnMap", lpnMap);
    settings.setValue("lpnPadding", ui->paddingSpinBox->value());
    settings.setValue("salvageLabel", ui->salvageLineEdit->text());
    settings.setValue("remoteMode", ui->remoteCheckbox->isChecked());
    settings.setValue("currentPrefix", ui->prefixComboBox->currentText());
    settings.setValue("copyClipboard", ui->copyCheckbox->isChecked());
    settings.setValue("lpnBatchMode", ui->lpnBatchModeCheckbox->isChecked());
    settings.setValue("listenPort", ui->listenPortSpinbox->value());

    settings.endGroup();

    //settings.sync();

}

void SettingsWindow::readSettings(){

    QSettings settings;

    settings.sync();

    settings.beginGroup("MainSettings");

    ui->remoteLineEdit->setText( settings.value("serverAddress").toString() );
    //ui->skuServerLineEdit->setText( settings.value("skuServerAddress").toString() );
    ui->skuServerCheckbox->setChecked( settings.value("skuServer").toBool() );
    ui->printServerLineEdit->setText( settings.value("printServer").toString() );
    ui->listenPortSpinbox->setValue( settings.value("listenPort").toInt() );
    ui->printerNameLineEdit->setText(settings.value("printerName").toString() );
    ui->printCommandLineEdit->setText ( settings.value("printCommand").toString() );
    ui->printCommandCheckbox->setChecked( settings.value("usePrintCommand").toBool() );
    ui->lpnBatchModeCheckbox->setChecked( settings.value("lpnBatchMode").toBool());

    ui->startMinimizedCheckbox->setChecked( settings.value("startMinimized").toBool());
    ui->enableSysTrayCheckbox->setChecked( settings.value("enableSystemTrayIcon").toBool());
    ui->minimizeToSysTrayCheckbox->setChecked( settings.value("minimizeToSystemTray").toBool());
    ui->sysTrayNotificationsCheckbox->setChecked( settings.value("systemTrayNotifications").toBool());


    QStringList prefixList;
    QVariantMap lpnMap = settings.value("lpnMap").toMap();
    for (auto it = lpnMap.begin(); it != lpnMap.end(); it++){
        prefixList.push_back(it.key());
    }
    ui->prefixComboBox->clear();
    ui->prefixComboBox->addItems( prefixList );
    QString currentPrefix = settings.value("currentPrefix", "LPN_").toString();
    int index = ui->prefixComboBox->findText(currentPrefix);
    ui->prefixComboBox->setCurrentIndex(index);
    ui->paddingSpinBox->setValue( settings.value("lpnPadding").toInt() );
    ui->salvageLineEdit->setText( settings.value("salvageLabel").toString() );
    ui->remoteCheckbox->setChecked( settings.value("remoteMode").toBool() );
    auto lpnPrefixMap = lpnMap.find(currentPrefix);
    if (lpnPrefixMap == lpnMap.end()) {
        qDebug() << "Error: could not find prefix \"" << currentPrefix << "\" in lpnMap!";
        qDebug() << "Using 0";
        ui->lpnSpinBox->setValue(0);
    } else {
        ui->lpnSpinBox->setValue( lpnPrefixMap.value().toInt() );
    }
    ui->copyCheckbox->setChecked( settings.value("copyClipboard").toBool() );

    settings.endGroup();

    if (ui->remoteCheckbox->isChecked()){
        ui->remoteLineEdit->setEnabled(true);
        ui->remoteSyncButton->setEnabled(true);
        ui->lpnFetchButton->setEnabled(true);
    } else {
        ui->remoteLineEdit->setEnabled(false);
        ui->remoteSyncButton->setEnabled(false);
        ui->lpnFetchButton->setEnabled(false);
    }

    if (ui->enableSysTrayCheckbox->isChecked()){
        ui->minimizeToSysTrayCheckbox->setEnabled(true);
        ui->sysTrayNotificationsCheckbox->setEnabled(true);
    } else {
        ui->minimizeToSysTrayCheckbox->setEnabled(false);
        ui->sysTrayNotificationsCheckbox->setEnabled(false);
    }

     ui->lpnSpinBox->setPrefix(Utils::lpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value(), true));
}

void SettingsWindow::on_settingsDialogButtons_accepted()
{
    saveSettings();
    close();
}

void SettingsWindow::on_settingsDialogButtons_rejected()
{
    close();
}

void SettingsWindow::on_settingsDialogButtons_clicked(QAbstractButton *button)
{
    QSettings settings;
    auto lpnMap = settings.value("lpnMap").toMap();
    switch (ui->settingsDialogButtons->buttonRole(button)){
    case QDialogButtonBox::ResetRole:
        settings.beginGroup("MainSettings");
        if (ui->tabWidget->currentIndex() == 2){
            qDebug() << "Resetting index 2 settings";
            settings.setValue("serverAddress", "https://retnuh.us");
            settings.setValue("skuServerAddress", "http://skufindnr.retnuh.us");
            settings.setValue("skuServer", false);
            settings.setValue("printServer", "localhost");
            settings.setValue("listenPort", 9457);
            settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
            settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");
            settings.setValue("usePrintCommand", true);
        } else if (ui->tabWidget->currentIndex() == 1) {
            qDebug() << "Resetting index 1 settings";
            settings.setValue("startMinimized", true);
            settings.setValue("enableSystemTrayIcon", true);
            settings.setValue("minimizeToSystemTray", true);
            settings.setValue("systemTrayNotifications", true);
        } else if (ui->tabWidget->currentIndex() == 0){
            qDebug() << "Resetting index 0 settings";
            if (lpnMap.find("LPN_") == lpnMap.end()){
                lpnMap.insert("LPN_", 0);
                settings.setValue("lpnMap", lpnMap);
            }
            settings.setValue("lpnPadding", 4);
            settings.setValue("salvageLabel", "svsvsv");
            settings.setValue("remoteMode", false);
            settings.setValue("currentPrefix", "LPN_");
            settings.setValue("copyClipboard", true);
        }

        settings.endGroup();

        settings.sync();

        readSettings();
        break;

    default:
        break;
    }
}

void SettingsWindow::on_deletePrefixButton_released()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning!");
    msgBox.setText("Deleting a prefix will reset the LPN counter for that prefix. Continue?");
    msgBox.setModal(true);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);
    QSettings settings;
    auto lpnMap = settings.value("MainSettings/lpnMap").toMap();
    switch(msgBox.exec()){

    case QMessageBox::Yes:
        lpnMap.remove(ui->prefixComboBox->currentText());
        settings.setValue("MainSettings/lpnMap", lpnMap);
        settings.setValue("MainSettings/currentPrefix", "");
        settings.sync();
        ui->prefixComboBox->removeItem(ui->prefixComboBox->currentIndex());
        break;

    default:
        break;
    }
}

void SettingsWindow::on_addPrefixButton_released()
{
    getStringDialog prefixDlg("Prefix: ");
    connect(&prefixDlg, SIGNAL(submitted(QString)), this, SLOT(on_submitted(QString)));
    prefixDlg.exec();
}

void SettingsWindow::on_submitted(QString prefix){
    if (ui->prefixComboBox->findText(prefix) == -1) ui->prefixComboBox->addItem(prefix);
    QSettings settings;
    QVariantMap lpnMap = settings.value("MainSettings/lpnMap").toMap();
    lpnMap.insert(prefix, 0);
    settings.setValue("MainSettings/lpnMap", lpnMap);
    settings.sync();
    ui->prefixComboBox->setCurrentIndex(ui->prefixComboBox->findText(prefix));
}

void SettingsWindow::on_paddingSpinBox_valueChanged(int value)
{
    if ( !init ) return;
    ui->lpnSpinBox->setPrefix(Utils::lpnPrefix(ui->prefixComboBox->currentText(), value, ui->lpnSpinBox->value(), true));
}

void SettingsWindow::on_prefixComboBox_currentIndexChanged(const QString &text)
{
    if ( !init ) return;
    if (text.isEmpty()) return;
    QSettings settings;

    settings.setValue("MainSettings/currentPrefix", text);
    settings.sync();

    ui->lpnSpinBox->setValue(Utils::getLPN(text));
    ui->lpnSpinBox->setPrefix(Utils::lpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value(), true));
}

void SettingsWindow::on_lpnSpinBox_valueChanged(int value)
{
    if ( !init ) return;
    ui->lpnSpinBox->setPrefix(Utils::lpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), value, true));
}

//void SettingsWindow::on_remoteModeCheckbox_stateChanged(int remoteMode)
//{
//    if (remoteMode){
//        ui->remoteLineEdit->setEnabled(true);
//        ui->remoteSyncButton->setEnabled(true);
//        ui->lpnFetchButton->setEnabled(true);
//    } else {
//        ui->remoteLineEdit->setEnabled(false);
//        ui->remoteSyncButton->setEnabled(false);
//        ui->lpnFetchButton->setEnabled(false);
//    }
//}

void SettingsWindow::on_lpnSetButton_released()
{
    QMessageBox msgBox;
    msgBox.setWindowTitle("Warning!");
    msgBox.setText("Setting the current LPN will OVERWRITE the stored LPN for this prefix. Continue?");
    msgBox.setModal(true);
    msgBox.setStandardButtons(QMessageBox::Yes | QMessageBox::No);
    msgBox.setDefaultButton(QMessageBox::No);

    QSettings settings;
    QVariantMap lpnMap;
    switch(msgBox.exec()){
    case QMessageBox::Yes:
        lpnMap = settings.value("MainSettings/lpnMap").toMap();
        lpnMap.remove(ui->prefixComboBox->currentText());
        lpnMap.insert(ui->prefixComboBox->currentText(), ui->lpnSpinBox->value());
        settings.setValue("MainSettings/lpnMap", lpnMap);
        settings.sync();
        break;

    default:
        ui->lpnSpinBox->setValue(Utils::getLPN(ui->prefixComboBox->currentText()));
        break;
    }
}

void SettingsWindow::on_skuServerCheckbox_stateChanged(int skuServer)
{
    (void) skuServer;
//    if (skuServer) {
//        ui->skuServerLineEdit->setEnabled(true);
//    } else {
//        ui->skuServerLineEdit->setEnabled(false);
//    }
}

void SettingsWindow::on_enableSysTrayCheckbox_stateChanged(int checked)
{
    if (checked == Qt::Checked){
        ui->minimizeToSysTrayCheckbox->setEnabled(true);
        ui->sysTrayNotificationsCheckbox->setEnabled(true);
    } else {
        ui->minimizeToSysTrayCheckbox->setEnabled(false);
        ui->sysTrayNotificationsCheckbox->setEnabled(false);
    }
}
