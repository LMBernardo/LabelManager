#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui{
class MainUI;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void initSettings();

private slots:
    void on_actionSettings_triggered();

    void on_actionExit_triggered();

private:
    Ui::MainUI *ui;
};

#endif // MAINWINDOW_H
