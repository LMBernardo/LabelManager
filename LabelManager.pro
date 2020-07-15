#-------------------------------------------------
#
# Project created by QtCreator 2019-01-09T00:41:44
#
#-------------------------------------------------

QT       += core gui network websockets printsupport

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

CONFIG += c++11 debug_and_release

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    settingswindow.cpp \
    getstringdialog.cpp \
    labelserver.cpp \
    labelclient.cpp \
    utils.cpp \
    websocket.cpp

HEADERS += \
        mainwindow.h \
    settingswindow.h \
    getstringdialog.h \
    labelserver.h \
    labelclient.h \
    utils.h \
    websocket.h

# Default rules for deployment.
 qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /usr/bin
!isEmpty(target.path): INSTALLS += target

# .desktop file
desktop.path = ~/.local/share/applications/
desktop.files = ./LabelManager.desktop

# Application icon
unix: icon.path = /usr/share/icons/
unix: icon.files = ./icons/icon-48.png
unix: icon.commands += mv (INSTALL_ROOT)/usr/share/icons/icon-48.png $(INSTALL_ROOT)/usr/share/icons/labelmanager.png;

# print_label.sh
unix: print_script.path = /usr/bin/
unix: print_script.files = ./print_label.sh

# Set execute permissions on print_label script
unix: print_script_post.path = ./
unix: print_script_post.commands += chmod +x $(INSTALL_ROOT)/usr/bin/print_label.sh;

unix: QMAKE_EXTRA_TARGETS += print_script_post

unix: INSTALLS += desktop icon print_script print_script_post
else: INSTALLS += desktop

RESOURCES += \
    resources.qrc

FORMS += \
    mainwindow.ui \
    settingswindow.ui \
    getstringdialog.ui

unix: DISTFILES += \
    print_label.sh
