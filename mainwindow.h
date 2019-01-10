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

private:
    Ui::MainUI *ui;
    QString lpnPrefix(QString prefix, int padding, int lpn);
};

#endif // MAINWINDOW_H
