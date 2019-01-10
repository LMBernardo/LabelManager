#include "mainwindow.h"
#include <QApplication>
#include "QDebug"

// Uncomment to disable debug output (qInfo, qDebug, qWarning, qCritical. qFatal)
//#define QT_NO_DEBUG_OUTPUT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initSettings();
    w.updateUi();

    w.show();

    return a.exec();
}
