#include "getstringdialog.h"
#include "ui_getstringdialog.h"

getStringDialog::getStringDialog(QString text, QWidget *parent) :
    QDialog(parent, Qt::CustomizeWindowHint),
    ui(new Ui::getStringDialog)
{
    ui->setupUi(this);
    ui->getStringLabel->setText(text);
}

getStringDialog::~getStringDialog()
{
    delete ui;
}

void getStringDialog::on_buttonBox_accepted()
{
    emit submitted(ui->getStringLineEdit->text());
    emit done(QDialog::Accepted);
}
