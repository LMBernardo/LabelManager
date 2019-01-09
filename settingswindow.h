#ifndef SETTINGSWINDOW_H
#define SETTINGSWINDOW_H

#include <QDialog>
#include <QSettings>
#include <QAbstractButton>

namespace Ui {
class SettingsUI;
}

class SettingsWindow : public QDialog
{
    Q_OBJECT

public:
    explicit SettingsWindow(QWidget *parent = nullptr);
    ~SettingsWindow();

    void saveSettings();
    void readSettings();

private slots:
    void on_settingsDialogButtons_accepted();

    void on_settingsDialogButtons_rejected();

    void on_settingsDialogButtons_clicked(QAbstractButton *button);

private:
    Ui::SettingsUI *ui;
    QSettings settings;
};

#endif // SETTINGSWINDOW_H
