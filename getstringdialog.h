#ifndef GETSTRINGDIALOG_H
#define GETSTRINGDIALOG_H

#include <QDialog>

namespace Ui {
class getStringDialog;
}

class getStringDialog : public QDialog
{
    Q_OBJECT

public:
    explicit getStringDialog(QString text, QWidget *parent = nullptr);
    ~getStringDialog();

signals:
    void submitted(QString);

private slots:
    void on_buttonBox_accepted();

private:
    Ui::getStringDialog *ui;
};

#endif // GETSTRINGDIALOG_H
