#include "mainwindow.h"
#include <QApplication>
#include "QDebug"
#include "utils.h"

#include "labelserver.h"
#include "labelclient.h"

// Uncomment to disable debug output (qInfo, qDebug, qWarning, qCritical. qFatal)
//#define QT_NO_DEBUG_OUTPUT

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QApplication::setOrganizationName("retco");
    QApplication::setOrganizationDomain("retnuh.us");
    QApplication::setApplicationName("LabelManager");

    labelServer ls;
    labelClient lc;

    lc.sendData("Test Data");

    MainWindow w;
    w.updateUi();

    w.show();

    return a.exec();
}
