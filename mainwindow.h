#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileSystemWatcher>
#include <QMainWindow>
#include <QSettings>
#include <QCoreApplication>
#include <QSettings>
#include <QDebug>
#include <QProcess>
#include <QClipboard>
#include <QMessageBox>
#include <QSystemTrayIcon>
#include <QCloseEvent>
// Unused at the moment
// #include <QtSerialPort/QSerialPort>
// #include <QtSerialPort/QSerialPortInfo>

#include "labelserver.h"
#include "labelclient.h"

#include "websocket.h"
#include "utils.h"

namespace Ui{
class MainUI;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init();
    void initSettings();
    void updateUi();

    // Overload closeEvent in order to show confirmation dialog
    void closeEvent(QCloseEvent* event);
    // Overload changeEvent to minimize to system tray
    void changeEvent(QEvent* event);

private slots:

    void on_contextMenuExit();

    void on_sysTrayActivated(QSystemTrayIcon::ActivationReason reason);

    void on_settingsChange(const QString sFile);

    void on_actionSettings_triggered();

    void on_actionExit_triggered();

    void on_printLPNButton_released();

    void on_printSKUButton_released();

    void on_printTextButton_released();

    void on_printSalvageButton_released();

    void on_lpnQuantitySpinBox_valueChanged(int arg1);

    void on_skuQuantitySpinBox_valueChanged(int arg1);

    void on_textQuantitySpinBox_valueChanged(int arg1);

    void on_reprintLPNButton_released();

    //void on_lpnLineEdit_returnPressed();

    void on_skuLineEdit_returnPressed();

    void on_textLineEdit_returnPressed();

    void on_wsMessageReceived(const QString arg1);

private:
    Ui::MainUI *ui;
    Utils utils;
    QIcon* icon;
    labelServer* lServer;
    labelClient* lClient;
    webSocket* wsServer;
    QSystemTrayIcon* sysTray;
    QMenu* sysTrayMenu;
    int printLabel(QString command = "", QString label = "");
};

#endif // MAINWINDOW_H
