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

    QCoreApplication::setOrganizationName("retco");
    QCoreApplication::setOrganizationDomain("retnuh.us");
    QCoreApplication::setApplicationName("LabelManager");

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

    settings.beginGroup("MainSettings");

    settings.setValue("serverAddress", ui->addressLineEdit->text());
    QVariantMap lpnMap;
    for (int i = 0; i < ui->prefixComboBox->count(); i++){
        lpnMap.insert(ui->prefixComboBox->itemText(i), settings.value("lpnMap").toMap().find(ui->prefixComboBox->itemText(i)).value().toString());
    }
    settings.setValue("lpnMap", lpnMap);
    settings.setValue("lpnPadding", ui->paddingSpinBox->value());
    settings.setValue("salvageLabel", ui->salvageLineEdit->text());
    settings.setValue("remoteMode", ui->remoteModeCheckbox->isChecked());
    settings.setValue("currentPrefix", ui->prefixComboBox->currentText());

    settings.endGroup();

    settings.sync();

}

void SettingsWindow::readSettings(){

    settings.beginGroup("MainSettings");

    ui->addressLineEdit->setText( settings.value("serverAddress").toString() );
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
    ui->lpnSpinBox->setValue( lpnMap[settings.value("currentPrefix").toString()].toInt() );

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

    emit(getLpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value()));
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
    QStringList prefixes = {"LPN_"};
    switch (ui->settingsDialogButtons->buttonRole(button)){

    case QDialogButtonBox::ResetRole:
        settings.beginGroup("MainSettings");

        settings.setValue("serverAddress", "https://retnuh.us");
        settings.setValue("labelPrefixList", prefixes);
        settings.setValue("lpnPadding", 4);
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("remoteMode", true);
        settings.endGroup();

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

void SettingsWindow::on_paddingSpinBox_valueChanged()
{
    if ( !init ) return;
    emit(getLpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value()));
}

void SettingsWindow::on_prefixComboBox_currentIndexChanged()
{
    if ( !init ) return;
    emit(getLpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value()));
}

void SettingsWindow::on_lpnSpinBox_valueChanged()
{
    if ( !init ) return;
    emit(getLpnPrefix(ui->prefixComboBox->currentText(), ui->paddingSpinBox->value(), ui->lpnSpinBox->value()));
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

    switch(msgBox.exec()){
    case QMessageBox::Yes:
        settings.value("MainSettings/lpnMap").toMap().find( ui->prefixComboBox->currentText() ).value().toMap().first().toInt();
        qInfo() << settings.value("MainSettings/lpnMap").toMap();
        break;

    default:
        break;
    }
}
