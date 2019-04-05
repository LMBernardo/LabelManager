#-------------------------------------------------
#
# Project created by QtCreator 2019-01-09T00:41:44
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = LabelManager
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settingswindow.cpp \
    getstringdialog.cpp \
    labelserver.cpp \
    labelclient.cpp \
    utils.cpp

HEADERS += \
        mainwindow.h \
    settingswindow.h \
    getstringdialog.h \
    labelserver.h \
    labelclient.h \
    utils.h

# Default rules for deployment.
 qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /usr/bin
!isEmpty(target.path): INSTALLS += target

# .desktop file
desktop.path = ~/.local/share/applications/
desktop.files = ./LabelManager.desktop
INSTALLS += desktop

RESOURCES += \
    resources.qrc

FORMS += \
    mainwindow.ui \
    settingswindow.ui \
    getstringdialog.ui
