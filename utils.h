#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QDebug>

#include <QMainWindow>

class Utils : public QObject
{
    Q_OBJECT
public:
    explicit Utils(QObject *parent = nullptr);

    static int getLPN(QString prefix);
    static QString lpnPrefix(QString prefix, int padding, int lpn, bool prefixOnly = false);
    static QString getFullLPN(QString prefix);
    void initSettings(QObject *caller);

    QFileSystemWatcher settingsWatcher;

signals:

public slots:
    void on_settingsChange(QString sFile);

};

#endif // UTILS_H
