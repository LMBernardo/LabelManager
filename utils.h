#ifndef UTILS_H
#define UTILS_H

#include <QObject>
#include <QString>
#include <QSettings>
#include <QFileSystemWatcher>
#include <QDebug>

#include <QMainWindow>

class utils : public QObject
{
    Q_OBJECT
public:
    //explicit utils(QObject *parent = nullptr);

    static int getLPN(QString prefix);
    static QString lpnPrefix(QString prefix, int padding, int lpn);
    static QString getFullLPN(QString prefix);
    static void initSettings(QObject *caller);

    static QFileSystemWatcher settingsWatcher;

signals:

public slots:
    static void on_settingsChange(QString sFile);

};

#endif // UTILS_H
