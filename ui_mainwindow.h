/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainUI
{
public:
    QAction *actionSettings;
    QAction *actionExit;
    QAction *actionAbout;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLabel *label;
    QLineEdit *lpnLineEdit;
    QSpinBox *lpnQuantitySpinBox;
    QPushButton *printLPNButton;
    QPushButton *reprintLPNButton;
    QLabel *lpnStatus;
    QLabel *label_2;
    QLineEdit *skuLineEdit;
    QSpinBox *skuQuantitySpinBox;
    QPushButton *printSKUButton;
    QPushButton *fetchSKUButton;
    QLabel *skuStatus;
    QLabel *label_3;
    QLineEdit *textLineEdit;
    QSpinBox *textQuantitySpinBox;
    QPushButton *printTextButton;
    QPushButton *printSalvageButton;
    QMenuBar *menubar;
    QMenu *menuMenu;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainUI)
    {
        if (MainUI->objectName().isEmpty())
            MainUI->setObjectName(QString::fromUtf8("MainUI"));
        MainUI->resize(480, 129);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainUI->sizePolicy().hasHeightForWidth());
        MainUI->setSizePolicy(sizePolicy);
        actionSettings = new QAction(MainUI);
        actionSettings->setObjectName(QString::fromUtf8("actionSettings"));
        actionExit = new QAction(MainUI);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionAbout = new QAction(MainUI);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        centralwidget = new QWidget(MainUI);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        centralwidget->setMinimumSize(QSize(480, 0));
        centralwidget->setMaximumSize(QSize(463, 85));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label, 0, 0, 1, 1);

        lpnLineEdit = new QLineEdit(centralwidget);
        lpnLineEdit->setObjectName(QString::fromUtf8("lpnLineEdit"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lpnLineEdit->sizePolicy().hasHeightForWidth());
        lpnLineEdit->setSizePolicy(sizePolicy1);
        lpnLineEdit->setMinimumSize(QSize(115, 0));
        lpnLineEdit->setReadOnly(true);

        gridLayout->addWidget(lpnLineEdit, 0, 1, 1, 1);

        lpnQuantitySpinBox = new QSpinBox(centralwidget);
        lpnQuantitySpinBox->setObjectName(QString::fromUtf8("lpnQuantitySpinBox"));
        lpnQuantitySpinBox->setMinimum(1);
        lpnQuantitySpinBox->setMaximum(500);

        gridLayout->addWidget(lpnQuantitySpinBox, 0, 2, 1, 1);

        printLPNButton = new QPushButton(centralwidget);
        printLPNButton->setObjectName(QString::fromUtf8("printLPNButton"));
        printLPNButton->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(printLPNButton, 0, 3, 1, 1);

        reprintLPNButton = new QPushButton(centralwidget);
        reprintLPNButton->setObjectName(QString::fromUtf8("reprintLPNButton"));

        gridLayout->addWidget(reprintLPNButton, 0, 4, 1, 1);

        lpnStatus = new QLabel(centralwidget);
        lpnStatus->setObjectName(QString::fromUtf8("lpnStatus"));
        lpnStatus->setEnabled(true);
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lpnStatus->sizePolicy().hasHeightForWidth());
        lpnStatus->setSizePolicy(sizePolicy2);
        lpnStatus->setMaximumSize(QSize(20, 20));
        lpnStatus->setPixmap(QPixmap(QString::fromUtf8(":/res/cross.png")));
        lpnStatus->setScaledContents(true);

        gridLayout->addWidget(lpnStatus, 0, 5, 1, 1);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        skuLineEdit = new QLineEdit(centralwidget);
        skuLineEdit->setObjectName(QString::fromUtf8("skuLineEdit"));
        sizePolicy1.setHeightForWidth(skuLineEdit->sizePolicy().hasHeightForWidth());
        skuLineEdit->setSizePolicy(sizePolicy1);
        skuLineEdit->setMinimumSize(QSize(115, 0));

        gridLayout->addWidget(skuLineEdit, 1, 1, 1, 1);

        skuQuantitySpinBox = new QSpinBox(centralwidget);
        skuQuantitySpinBox->setObjectName(QString::fromUtf8("skuQuantitySpinBox"));
        skuQuantitySpinBox->setMinimum(1);
        skuQuantitySpinBox->setMaximum(500);
        skuQuantitySpinBox->setSingleStep(1);

        gridLayout->addWidget(skuQuantitySpinBox, 1, 2, 1, 1);

        printSKUButton = new QPushButton(centralwidget);
        printSKUButton->setObjectName(QString::fromUtf8("printSKUButton"));
        printSKUButton->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(printSKUButton, 1, 3, 1, 1);

        fetchSKUButton = new QPushButton(centralwidget);
        fetchSKUButton->setObjectName(QString::fromUtf8("fetchSKUButton"));

        gridLayout->addWidget(fetchSKUButton, 1, 4, 1, 1);

        skuStatus = new QLabel(centralwidget);
        skuStatus->setObjectName(QString::fromUtf8("skuStatus"));
        sizePolicy2.setHeightForWidth(skuStatus->sizePolicy().hasHeightForWidth());
        skuStatus->setSizePolicy(sizePolicy2);
        skuStatus->setMaximumSize(QSize(20, 20));
        skuStatus->setPixmap(QPixmap(QString::fromUtf8(":/res/cross.png")));
        skuStatus->setScaledContents(true);

        gridLayout->addWidget(skuStatus, 1, 5, 1, 1);

        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        textLineEdit = new QLineEdit(centralwidget);
        textLineEdit->setObjectName(QString::fromUtf8("textLineEdit"));
        textLineEdit->setMinimumSize(QSize(125, 0));
        textLineEdit->setClearButtonEnabled(false);

        gridLayout->addWidget(textLineEdit, 2, 1, 1, 1);

        textQuantitySpinBox = new QSpinBox(centralwidget);
        textQuantitySpinBox->setObjectName(QString::fromUtf8("textQuantitySpinBox"));
        textQuantitySpinBox->setMinimum(1);
        textQuantitySpinBox->setMaximum(500);

        gridLayout->addWidget(textQuantitySpinBox, 2, 2, 1, 1);

        printTextButton = new QPushButton(centralwidget);
        printTextButton->setObjectName(QString::fromUtf8("printTextButton"));
        printTextButton->setMaximumSize(QSize(60, 16777215));

        gridLayout->addWidget(printTextButton, 2, 3, 1, 1);

        printSalvageButton = new QPushButton(centralwidget);
        printSalvageButton->setObjectName(QString::fromUtf8("printSalvageButton"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(printSalvageButton->sizePolicy().hasHeightForWidth());
        printSalvageButton->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(printSalvageButton, 2, 4, 1, 1);

        MainUI->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainUI);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 480, 20));
        menuMenu = new QMenu(menubar);
        menuMenu->setObjectName(QString::fromUtf8("menuMenu"));
        menuHelp = new QMenu(menubar);
        menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
        MainUI->setMenuBar(menubar);
        statusbar = new QStatusBar(MainUI);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainUI->setStatusBar(statusbar);

        menubar->addAction(menuMenu->menuAction());
        menubar->addAction(menuHelp->menuAction());
        menuMenu->addAction(actionSettings);
        menuMenu->addAction(actionExit);
        menuHelp->addAction(actionAbout);

        retranslateUi(MainUI);

        QMetaObject::connectSlotsByName(MainUI);
    } // setupUi

    void retranslateUi(QMainWindow *MainUI)
    {
        MainUI->setWindowTitle(QCoreApplication::translate("MainUI", "Label Manager", nullptr));
        actionSettings->setText(QCoreApplication::translate("MainUI", "&Settings", nullptr));
        actionExit->setText(QCoreApplication::translate("MainUI", "&Exit", nullptr));
        actionAbout->setText(QCoreApplication::translate("MainUI", "About...", nullptr));
        label->setText(QCoreApplication::translate("MainUI", "Current LPN:", nullptr));
        lpnLineEdit->setPlaceholderText(QCoreApplication::translate("MainUI", "Fetch to populate", nullptr));
        printLPNButton->setText(QCoreApplication::translate("MainUI", "Print", nullptr));
#if QT_CONFIG(tooltip)
        reprintLPNButton->setToolTip(QCoreApplication::translate("MainUI", "Reprint previous LPN", nullptr));
#endif // QT_CONFIG(tooltip)
        reprintLPNButton->setText(QCoreApplication::translate("MainUI", "Reprint", nullptr));
        label_2->setText(QCoreApplication::translate("MainUI", "Current SKU:", nullptr));
        skuLineEdit->setPlaceholderText(QCoreApplication::translate("MainUI", "Fetch to populate", nullptr));
        printSKUButton->setText(QCoreApplication::translate("MainUI", "Print", nullptr));
        fetchSKUButton->setText(QCoreApplication::translate("MainUI", "Fetch", nullptr));
        label_3->setText(QCoreApplication::translate("MainUI", "Print Text:", nullptr));
        printTextButton->setText(QCoreApplication::translate("MainUI", "Print", nullptr));
        printSalvageButton->setText(QCoreApplication::translate("MainUI", "Salvage", nullptr));
        menuMenu->setTitle(QCoreApplication::translate("MainUI", "Menu", nullptr));
        menuHelp->setTitle(QCoreApplication::translate("MainUI", "Help", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainUI: public Ui_MainUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
