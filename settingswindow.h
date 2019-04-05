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

    void initSettingsWindow();

private slots:
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

    //void on_remoteModeCheckbox_stateChanged(int arg1);

    void on_lpnSetButton_released();

    void on_skuServerCheckbox_stateChanged(int arg1);

private:
    Ui::SettingsUI *ui;

    bool init = false;

    void saveSettings();
    void readSettings();

    //void keyPressEvent(QKeyEvent *evt);
};

#endif // SETTINGSWINDOW_H
