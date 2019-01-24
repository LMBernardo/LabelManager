#include "getstringdialog.h"
#include "settingswindow.h"
#include "ui_settingswindow.h"

#include <QCoreApplication>
#include <QSettings>
#include <QMessageBox>

#include <QDebug>

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsUI)
{
    ui->setupUi(this);

}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::initSettings(){
    readSettings();
    init = true;
}

void SettingsWindow::saveSettings(){

    qInfo() << "Saving settings...";

    QSettings settings;

    settings.sync();

    settings.beginGroup("MainSettings");

    settings.setValue("serverAddress", ui->addressLineEdit->text());
    settings.setValue("skuServerAddress", ui->skuServerLineEdit->text());
    settings.setValue("skuServer", ui->skuServerCheckbox->isChecked());
    settings.setValue("printServer", ui->printServerLineEdit->text());
    settings.setValue("printerName", ui->printerNameLineEdit->text());
    settings.setValue("printCommand", ui->printCommandLineEdit->text());
    QVariantMap lpnMap;
    for (int i = 0; i < ui->prefixComboBox->count(); i++){
        lpnMap.insert(ui->prefixComboBox->itemText(i), getLPN(ui->prefixComboBox->itemText(i)));
    }
    settings.setValue("lpnMap", lpnMap);
    settings.setValue("lpnPadding", ui->paddingSpinBox->value());
    settings.setValue("salvageLabel", ui->salvageLineEdit->text());
    settings.setValue("remoteMode", ui->remoteModeCheckbox->isChecked());
    settings.setValue("currentPrefix", ui->prefixComboBox->currentText());
    settings.setValue("copyClipboard", ui->copyCheckbox->isChecked());

    settings.endGroup();

    //settings.sync();

}

void SettingsWindow::readSettings(){

    QSettings settings;

    settings.sync();

    settings.beginGroup("MainSettings");

    ui->addressLineEdit->setText( settings.value("serverAddress").toString() );
    ui->skuServerLineEdit->setText( settings.value("skuServerAddress").toString() );
    ui->skuServerCheckbox->setChecked( settings.value("skuServer").toBool() );
    ui->printServerLineEdit->setText( settings.value("printServer").toString() );
    ui->printerNameLineEdit->setText(settings.value("printerName").toString() );
    ui->printCommandLineEdit->setText ( settings.value("printCommand").toString() );

    QStringList prefixList;
    QVariantMap lpnMap = settings.value("lpnMap").toMap();
    for (auto it = lpnMap.begin(); it != lpnMap.end(); it++){
        prefixList.push_back(it.key());
    }
    ui->prefixComboBox->addItems( prefixList );
    QString currentPrefix = settings.value("currentPrefix").toString();
    int index = ui->prefixComboBox->findText(currentPrefix);
    ui->prefixComboBox->setCurrentIndex(index);
    ui->paddingSpinBox->setValue( settings.value("lpnPadding").toInt() );
    ui->salvageLineEdit->setText( settings.value("salvageLabel").toString() );
    ui->remoteModeCheckbox->setChecked( settings.value("remoteMode").toBool() );
    ui->lpnSpinBox->setValue( lpnMap.find(currentPrefix).value().toInt() );
    ui->copyCheckbox->setChecked( settings.value("copyClipboard").toBool() );

    settings.endGroup();

    if (ui->remoteModeCheckbox->isChecked()){
        ui->addressLineEdit->setEnabled(true);
        ui->syncButton->setEnabled(true);
        ui->lpnFetchButton->setEnabled(true);
    } else {
        ui->addressLineEdit->setEnabled(false);
        ui->syncButton->setEnabled(false);
        ui->lpnFetchButton->setEnabled(false);
    }

    if (ui->skuServerCheckbox->isChecked()){
        ui->skuServerLineEdit->setEnabled(true);
    } else {
        ui->skuServerLineEdit->setEnabled(false);
    }

    emit(getLpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value()));
}

QString SettingsWindow::lpnPrefix(QString prefix, int padding, int lpn){
    int digits = 0; do { lpn /= 10; digits++; } while (lpn != 0);
    for (int i = 0; i < padding - digits; i++){
        prefix.append("0");
    }
    return prefix;
}


int SettingsWindow::getLPN(QString prefix){
    QSettings settings;
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    int lpn = settings.value("MainSettings/lpnMap").toMap().find(prefix).value().toInt();
    return lpn;
}

QString SettingsWindow::getFullLPN(QString prefix){
    QSettings settings;
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    int currentLPN = getLPN(prefix);
    QString lpnString = lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), currentLPN);
    lpnString.append(QString::number(currentLPN));
    return lpnString;
}

void SettingsWindow::on_lpnPrefixReturn(QString prefix){
    ui->lpnSpinBox->setPrefix(prefix);
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
    QVariantMap lpnMap;
    switch (ui->settingsDialogButtons->buttonRole(button)){
    case QDialogButtonBox::ResetRole:
        settings.beginGroup("MainSettings");

        if (ui->tabWidget->currentIndex() == 1){
            settings.setValue("serverAddress", "https://retnuh.us");
            settings.setValue("skuServerAddress", "http://skufindnr.retnuh.us");
            settings.setValue("skuServer", true);
            settings.setValue("printServer", "localhost");
            settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
            settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME $FULL_LPN");
        } else {
            lpnMap.insert("LPN_", 1);
            settings.setValue("lpnMap", lpnMap);
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

    switch(msgBox.exec()){

    case QMessageBox::Yes:
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
}

void SettingsWindow::on_paddingSpinBox_valueChanged(int value)
{
    if ( !init ) return;
    emit(getLpnPrefix(ui->prefixComboBox->currentText(), value, ui->lpnSpinBox->value()));
}

void SettingsWindow::on_prefixComboBox_currentIndexChanged(const QString &text)
{
    if ( !init ) return;
    QSettings settings;

    settings.setValue("MainSettings/currentPrefix", text);
    settings.sync();

    ui->lpnSpinBox->setValue(getLPN(text));
    emit(getLpnPrefix(text, ui->paddingSpinBox->value(), ui->lpnSpinBox->value()));
}

void SettingsWindow::on_lpnSpinBox_valueChanged(int value)
{
    if ( !init ) return;
    emit(getLpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), value));
}

void SettingsWindow::on_remoteModeCheckbox_stateChanged(int remoteMode)
{
    if (remoteMode){
        ui->addressLineEdit->setEnabled(true);
        ui->syncButton->setEnabled(true);
        ui->lpnFetchButton->setEnabled(true);
    } else {
        ui->addressLineEdit->setEnabled(false);
        ui->syncButton->setEnabled(false);
        ui->lpnFetchButton->setEnabled(false);
    }
}

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
        ui->lpnSpinBox->setValue(getLPN(ui->prefixComboBox->currentText()));
        break;
    }
}

void SettingsWindow::on_skuServerCheckbox_stateChanged(int skuServer)
{
    if (skuServer) {
        ui->skuServerLineEdit->setEnabled(true);
    } else {
        ui->skuServerLineEdit->setEnabled(false);
    }
}
