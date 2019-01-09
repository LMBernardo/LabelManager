#include "settingswindow.h"
#include "ui_settingswindow.h"

#include "QCoreApplication"
#include "QSettings"

SettingsWindow::SettingsWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SettingsUI)
{
    ui->setupUi(this);

    //    connect( ui->settingsDialogButtons, SIGNAL(accepted()), this, SLOT(accept()) );
    //    connect( ui->settingsDialogButtons, SIGNAL(rejected()), this, SLOT(reject()) );

    QCoreApplication::setOrganizationName("RetCo");
    QCoreApplication::setOrganizationDomain("retnuh.us");
    QCoreApplication::setApplicationName("LabelManager");

    readSettings();
}

SettingsWindow::~SettingsWindow()
{
    delete ui;
}

void SettingsWindow::saveSettings(){

    settings.beginGroup("MainSettings");

    settings.setValue("serverAddress", ui->addressLineEdit->text());
    settings.setValue("labelPrefix", ui->prefixLineEdit->text());
    settings.setValue("salvageLabel", ui->salvageLineEdit->text());
    settings.setValue("localMode", ui->localModeCheckbox->isChecked());

    settings.endGroup();

    settings.sync();

}

void SettingsWindow::readSettings(){

    settings.beginGroup("MainSettings");

    ui->addressLineEdit->setText( settings.value("serverAddress").toString() );
    ui->prefixLineEdit->setText( settings.value("labelPrefix").toString() );
    ui->salvageLineEdit->setText( settings.value("salvageLabel").toString() );
    ui->localModeCheckbox->setChecked( settings.value("localMode").toBool() );

    settings.endGroup();
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
    switch (ui->settingsDialogButtons->buttonRole(button)){

    case QDialogButtonBox::ResetRole:
        settings.beginGroup("MainSettings");

        settings.setValue("serverAddress", "https://retnuh.us");
        settings.setValue("labelPrefix", "LPN_");
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("localMode", false);

        settings.endGroup();

        readSettings();
        break;

    default:
        break;
    }
}
