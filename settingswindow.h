#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QSettings>
#include <QAbstractButton>
#include <QKeyEvent>

namespace Ui {
class SettingsUI;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

    void initSettings();

    QString lpnPrefix(QString prefix, int padding, int lpn);
    int getLPN(QString prefix = "");
    QString getFullLPN(QString prefix = "");

signals:
    void getLpnPrefix(QString prefix = "", int padding = 0, int lpn = -1);

private slots:

    void on_lpnPrefixReturn(QString prefix);

    void on_submitted(QString);

    void on_settingsDialogButtons_accepted();

    void on_settingsDialogButtons_rejected();

    void on_settingsDialogButtons_clicked(QAbstractButton *button);

    void on_deletePrefixButton_released();

    void on_addPrefixButton_released();

    void on_paddingSpinBox_valueChanged(int value);
    //void on_paddingSpinBox_valueChanged();

    void on_prefixComboBox_currentIndexChanged(const QString &prefix);
    //void on_prefixComboBox_currentIndexChanged();

    void on_lpnSpinBox_valueChanged(int value);

    void on_remoteModeCheckbox_stateChanged(int arg1);

    void on_lpnSetButton_released();

private:
    Ui::SettingsUI *ui;
    QSettings settings;

    bool init = false;

    void saveSettings();
    void readSettings();

    //void keyPressEvent(QKeyEvent *evt);
};

#endif // SETTINGSWINDOW_H
