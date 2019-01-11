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

signals:
    void lpnPrefixReturn(QString prefix);

private slots:
    void on_getLpnPrefix(QString prefix, int padding, int lpn);

    void on_actionSettings_triggered();
    void on_actionExit_triggered();

    void on_printLPNButton_released();

    void on_printSKUButton_released();

    void on_printTextButton_released();

    void on_printSalvageButton_released();

private:
    Ui::MainUI *ui;
    QSettings settings;
    int getLPN(QString prefix = "");
    QString getFullLPN(QString prefix = "");
    QString lpnPrefix(QString prefix, int padding, int lpn);
    int printLabel(QString command = "", QString label = "");
};

#endif // MAINWINDOW_H
