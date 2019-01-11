#include "mainwindow.h"
#include <QApplication>
#include "QDebug"

// Uncomment to disable debug output (qInfo, qDebug, qWarning, qCritical. qFatal)
//#define QT_NO_DEBUG_OUTPUT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QCoreApplication::setOrganizationName("retco");
    QCoreApplication::setOrganizationDomain("retnuh.us");
    QCoreApplication::setApplicationName("LabelManager");

    MainWindow w;
    w.initSettings();
    w.updateUi();

    w.show();

    return a.exec();
}
