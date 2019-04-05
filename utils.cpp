#include "utils.h"

QFileSystemWatcher utils::settingsWatcher;

//utils::utils(QObject *parent) : QObject(parent)
//{

//}

int utils::getLPN(QString prefix){
    QSettings settings;
    settings.sync();
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    //qInfo() << "Finding prefix:" << prefix;
    int lpn = settings.value("MainSettings/lpnMap").toMap().find(prefix).value().toInt();
    //qInfo() << "Returning LPN:" << QString("%1").arg(QString::number(lpn));
    return lpn;
}

QString utils::lpnPrefix(QString prefix, int padding, int lpn){
    int lpnInit = lpn;
    int digits = 0; do { lpn /= 10; digits++; } while (lpn != 0);
    for (int i = 0; i < padding - digits; i++){
        prefix.append("0");
    }
    return prefix + QString::number(lpnInit);
}

QString utils::getFullLPN(QString prefix){
    QSettings settings;
    settings.sync();
    if (prefix == "") prefix = settings.value("MainSettings/currentPrefix").toString();
    int currentLPN = getLPN(prefix);
    QString lpnString = lpnPrefix(prefix, settings.value("MainSettings/lpnPadding").toInt(), currentLPN);
    return lpnString;
}

void utils::initSettings(QObject *caller){

    QSettings settings;

    settings.sync();
    settings.beginGroup("MainSettings");

    if ( settings.allKeys().size() != 0 ) {

        if ( !settings.contains("serverAddress") ) {
            settings.setValue("serverAddress", "https://retnuh.us");
            qInfo() << "Config error! Using server address: https://retnuh.us";
        }

        if ( !settings.contains("skuServer") ) {
            settings.setValue("skuServer", false);
            qInfo() << "Config error! Using SKU server: false";
        }

        if ( !settings.contains("skuServerAddress") ) {
            settings.setValue("skuServerAddress", "http://skufindnr.retnuh.us");
            qInfo() << "Config error! Using SKU server address: http://skufindnr.retnuh.us";
        }

        if ( !settings.contains("printServer") ) {
            settings.setValue("printServer", "localhost");
            qInfo() << "Config error! Using print server: localhost";
        }

        if ( !settings.contains("printerName") ) {
            settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
            qInfo() << "Config error! Using printer name: Zebra_Technologies_ZTC_ZP_500_";
        }

        if ( !settings.contains("printCommand") ) {
            settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");
            qInfo() << "Config error! Using print command: /usr/bin/print_label.sh $PRINTER_NAME";
        }

        if ( !settings.contains("usePrintCommand") ) {
            settings.setValue("usePrintCommand", true);
            qInfo() << "Config error! Using print command enabled: true";
        }

        if ( !settings.contains("lpnMap") ) {
            QVariantMap lpnMap; lpnMap.insert("LPN_", 1);
            settings.setValue("lpnMap", lpnMap);
            qInfo() << "Config error! Using LPN map: { \"LPN_\", 1 }";
        }

        if ( !settings.contains("currentPrefix") ) {
            settings.setValue("currentPrefix", settings.value("lpnMap").toMap().begin().key() );
            qInfo() << "Config error! Using currentPrefix:" << settings.value("lpnMap").toMap().begin().key();
        }

        if ( !settings.contains("lpnPadding") ) {
            settings.setValue("lpnPadding", 4);
            qInfo() << "Config error! Using LPN padding: 4";
        }

        if ( !settings.contains("salvageLabel") ) {
            settings.setValue("salvageLabel", "svsvsv");
            qInfo() << "Config error! Using salvage label: svsvsv";
        }

        if ( !settings.contains("remoteMode") ) {
            settings.setValue("remoteMode", false);
            qInfo() << "Config error! Using remote mode: false";
        }

        if ( !settings.contains("copyClipboard") ) {
            settings.setValue("copyClipboard", true);
            qInfo() << "Config error! Using copy to clipboard: true";
        }

        qInfo() << "Configuration loaded.\n";
    } else {
        qInfo() << "Config not found, using default settings.";
        settings.setValue("serverAddress", "https://retnuh.us");
        settings.setValue("skuServer", false);
        settings.setValue("skuServerAddress", "http://skufindnr.retnuh.us");
        settings.setValue("printServer", "localhost");
        settings.setValue("printerName", "Zebra_Technologies_ZTC_ZP_500_");
        settings.setValue("printCommand", "/usr/bin/print_label.sh $PRINTER_NAME");
        settings.setValue("usePrintCommand", true);

        QVariantMap lpnMap; lpnMap.insert("LPN_", 1);
        settings.setValue("lpnMap", lpnMap);
        settings.setValue("lpnPadding", 4);
        settings.setValue("salvageLabel", "svsvsv");
        settings.setValue("remoteMode", false);
        settings.setValue("currentPrefix", "LPN_");
        settings.setValue("copyClipboard", true);
    }

    settings.endGroup();

    settings.beginGroup("UI");

    if ( settings.allKeys().size() != 0 ) {
        if ( !settings.contains("printQuantity") ) {
            QVariantList printQuantity = {1, 1, 1};
            settings.setValue("printQuantity", printQuantity);
            qInfo() << "Config error! Using printQuantity: {1, 1, 1}";
        }
    } else {
        QVariantList printQuantity = {1, 1, 1};
        settings.setValue("printQuantity", printQuantity);
    }

    // Watch settings file for changes (signal to caller & utils)
    settingsWatcher.addPath(settings.fileName());
    connect(&settingsWatcher, SIGNAL(fileChanged(const QString)), caller, SLOT(on_settingsChange(const QString)));
    connect(&settingsWatcher, &QFileSystemWatcher::fileChanged, utils::on_settingsChange);

    // Probably not necessary, should happen when we leave scope
    settings.sync();
}

void utils::on_settingsChange(const QString sFile){
    // Watch file again in case file has been updated by being replaced
    settingsWatcher.addPath(sFile);
}
