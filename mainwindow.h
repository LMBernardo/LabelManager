#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSettings>

namespace Ui{
class MainUI;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void initSettings();
    void updateUi();

private slots:

    void on_actionSettings_triggered();
    void on_actionExit_triggered();

    void on_printLPNButton_released();

    void on_printSKUButton_released();

    void on_printTextButton_released();

    void on_printSalvageButton_released();

    void on_lpnQuantitySpinBox_valueChanged(int arg1);

    void on_skuQuantitySpinBox_valueChanged(int arg1);

    void on_textQuantitySpinBox_valueChanged(int arg1);

private:
    Ui::MainUI *ui;
    int getLPN(QString prefix = "");
    QString getFullLPN(QString prefix = "");
    QString lpnPrefix(QString prefix, int padding, int lpn);
    int printLabel(QString command = "", QString label = "");
};

#endif // MAINWINDOW_H
