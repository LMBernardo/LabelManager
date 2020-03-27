/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGSWINDOW_H
#define UI_SETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingsUI
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *labelSettingsTab;
    QGridLayout *gridLayout_3;
    QSpacerItem *verticalSpacer;
    QGridLayout *SettingsLayout;
    QLabel *lpnLabel;
    QComboBox *prefixComboBox;
    QPushButton *lpnSetButton;
    QLineEdit *salvageLineEdit;
    QSpinBox *paddingSpinBox;
    QPushButton *deletePrefixButton;
    QCheckBox *copyCheckbox;
    QLabel *copyLabel;
    QPushButton *addPrefixButton;
    QLabel *salvageLabel;
    QSpinBox *lpnSpinBox;
    QLabel *paddingLabel;
    QPushButton *lpnFetchButton;
    QLabel *prefixLabel;
    QCheckBox *lpnBatchModeCheckbox;
    QLabel *lpnBatchModeLabel;
    QSpacerItem *horizontalSpacer_2;
    QWidget *generalSettingsTab;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *minimizeToSysTrayLabel;
    QCheckBox *enableSysTrayCheckbox;
    QCheckBox *startMinimizedCheckbox;
    QCheckBox *sysTrayNotificationsCheckbox;
    QLabel *sysTrayNotificationsLabel;
    QCheckBox *minimizeToSysTrayCheckbox;
    QSpacerItem *verticalSpacer_3;
    QLabel *startMinimizedLabel;
    QLabel *enableSysTrayLabel;
    QSpacerItem *horizontalSpacer;
    QWidget *advancedSettingsTab;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *wsPortSpinbox;
    QCheckBox *wsServerCheckbox;
    QLabel *listenPortLabel;
    QSpinBox *listenPortSpinbox;
    QCheckBox *skuServerCheckbox;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *printCommandLineEdit;
    QCheckBox *printCommandCheckbox;
    QLabel *label;
    QLineEdit *printServerLineEdit;
    QLabel *printCommandLabel;
    QLabel *printerNameLabel;
    QSpacerItem *verticalSpacer_2;
    QLabel *printServerLabel;
    QLabel *listenPortLabel_2;
    QLineEdit *printerNameLineEdit;
    QGridLayout *gridLayout_4;
    QLineEdit *remoteLineEdit;
    QPushButton *remoteSyncButton;
    QCheckBox *remoteCheckbox;
    QLabel *remoteLabel;
    QLineEdit *formatStringLineEdit;
    QDialogButtonBox *settingsDialogButtons;

    void setupUi(QDialog *SettingsUI)
    {
        if (SettingsUI->objectName().isEmpty())
            SettingsUI->setObjectName(QString::fromUtf8("SettingsUI"));
        SettingsUI->setWindowModality(Qt::ApplicationModal);
        SettingsUI->resize(481, 244);
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsUI->sizePolicy().hasHeightForWidth());
        SettingsUI->setSizePolicy(sizePolicy);
        SettingsUI->setMinimumSize(QSize(0, 244));
        SettingsUI->setMaximumSize(QSize(640, 280));
        SettingsUI->setModal(true);
        verticalLayout = new QVBoxLayout(SettingsUI);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(5, -1, -1, 7);
        tabWidget = new QTabWidget(SettingsUI);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        sizePolicy.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy);
        tabWidget->setMinimumSize(QSize(0, 180));
        tabWidget->setMaximumSize(QSize(16777215, 200));
        labelSettingsTab = new QWidget();
        labelSettingsTab->setObjectName(QString::fromUtf8("labelSettingsTab"));
        labelSettingsTab->setMaximumSize(QSize(16777215, 156));
        gridLayout_3 = new QGridLayout(labelSettingsTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        SettingsLayout = new QGridLayout();
        SettingsLayout->setObjectName(QString::fromUtf8("SettingsLayout"));
        SettingsLayout->setContentsMargins(5, -1, 5, -1);
        lpnLabel = new QLabel(labelSettingsTab);
        lpnLabel->setObjectName(QString::fromUtf8("lpnLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(lpnLabel->sizePolicy().hasHeightForWidth());
        lpnLabel->setSizePolicy(sizePolicy1);
        lpnLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(lpnLabel, 1, 0, 1, 1);

        prefixComboBox = new QComboBox(labelSettingsTab);
        prefixComboBox->setObjectName(QString::fromUtf8("prefixComboBox"));
        QSizePolicy sizePolicy2(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(prefixComboBox->sizePolicy().hasHeightForWidth());
        prefixComboBox->setSizePolicy(sizePolicy2);
        prefixComboBox->setEditable(false);
        prefixComboBox->setMaxVisibleItems(10);
        prefixComboBox->setInsertPolicy(QComboBox::InsertAlphabetically);

        SettingsLayout->addWidget(prefixComboBox, 0, 1, 1, 1);

        lpnSetButton = new QPushButton(labelSettingsTab);
        lpnSetButton->setObjectName(QString::fromUtf8("lpnSetButton"));
        sizePolicy2.setHeightForWidth(lpnSetButton->sizePolicy().hasHeightForWidth());
        lpnSetButton->setSizePolicy(sizePolicy2);
        lpnSetButton->setMaximumSize(QSize(16777215, 16777215));

        SettingsLayout->addWidget(lpnSetButton, 1, 3, 1, 1);

        salvageLineEdit = new QLineEdit(labelSettingsTab);
        salvageLineEdit->setObjectName(QString::fromUtf8("salvageLineEdit"));
        sizePolicy2.setHeightForWidth(salvageLineEdit->sizePolicy().hasHeightForWidth());
        salvageLineEdit->setSizePolicy(sizePolicy2);

        SettingsLayout->addWidget(salvageLineEdit, 3, 1, 1, 3);

        paddingSpinBox = new QSpinBox(labelSettingsTab);
        paddingSpinBox->setObjectName(QString::fromUtf8("paddingSpinBox"));
        sizePolicy2.setHeightForWidth(paddingSpinBox->sizePolicy().hasHeightForWidth());
        paddingSpinBox->setSizePolicy(sizePolicy2);
        paddingSpinBox->setMinimum(1);
        paddingSpinBox->setMaximum(10);

        SettingsLayout->addWidget(paddingSpinBox, 2, 1, 1, 1);

        deletePrefixButton = new QPushButton(labelSettingsTab);
        deletePrefixButton->setObjectName(QString::fromUtf8("deletePrefixButton"));
        sizePolicy2.setHeightForWidth(deletePrefixButton->sizePolicy().hasHeightForWidth());
        deletePrefixButton->setSizePolicy(sizePolicy2);
        deletePrefixButton->setMaximumSize(QSize(16777215, 16777215));
        deletePrefixButton->setLayoutDirection(Qt::LeftToRight);

        SettingsLayout->addWidget(deletePrefixButton, 0, 3, 1, 1);

        copyCheckbox = new QCheckBox(labelSettingsTab);
        copyCheckbox->setObjectName(QString::fromUtf8("copyCheckbox"));
        copyCheckbox->setChecked(true);

        SettingsLayout->addWidget(copyCheckbox, 4, 1, 1, 1);

        copyLabel = new QLabel(labelSettingsTab);
        copyLabel->setObjectName(QString::fromUtf8("copyLabel"));
        copyLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(copyLabel, 4, 0, 1, 1);

        addPrefixButton = new QPushButton(labelSettingsTab);
        addPrefixButton->setObjectName(QString::fromUtf8("addPrefixButton"));
        sizePolicy2.setHeightForWidth(addPrefixButton->sizePolicy().hasHeightForWidth());
        addPrefixButton->setSizePolicy(sizePolicy2);
        addPrefixButton->setMaximumSize(QSize(60, 16777215));

        SettingsLayout->addWidget(addPrefixButton, 0, 2, 1, 1);

        salvageLabel = new QLabel(labelSettingsTab);
        salvageLabel->setObjectName(QString::fromUtf8("salvageLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(salvageLabel->sizePolicy().hasHeightForWidth());
        salvageLabel->setSizePolicy(sizePolicy3);
        salvageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(salvageLabel, 3, 0, 1, 1);

        lpnSpinBox = new QSpinBox(labelSettingsTab);
        lpnSpinBox->setObjectName(QString::fromUtf8("lpnSpinBox"));
        sizePolicy1.setHeightForWidth(lpnSpinBox->sizePolicy().hasHeightForWidth());
        lpnSpinBox->setSizePolicy(sizePolicy1);
        lpnSpinBox->setMinimumSize(QSize(110, 0));
        lpnSpinBox->setMaximumSize(QSize(115, 16777215));
        lpnSpinBox->setMaximum(99999999);
        lpnSpinBox->setValue(0);

        SettingsLayout->addWidget(lpnSpinBox, 1, 1, 1, 1);

        paddingLabel = new QLabel(labelSettingsTab);
        paddingLabel->setObjectName(QString::fromUtf8("paddingLabel"));
        sizePolicy3.setHeightForWidth(paddingLabel->sizePolicy().hasHeightForWidth());
        paddingLabel->setSizePolicy(sizePolicy3);
        paddingLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(paddingLabel, 2, 0, 1, 1);

        lpnFetchButton = new QPushButton(labelSettingsTab);
        lpnFetchButton->setObjectName(QString::fromUtf8("lpnFetchButton"));
        sizePolicy2.setHeightForWidth(lpnFetchButton->sizePolicy().hasHeightForWidth());
        lpnFetchButton->setSizePolicy(sizePolicy2);
        lpnFetchButton->setMaximumSize(QSize(60, 16777215));
        lpnFetchButton->setLayoutDirection(Qt::LeftToRight);

        SettingsLayout->addWidget(lpnFetchButton, 1, 2, 1, 1);

        prefixLabel = new QLabel(labelSettingsTab);
        prefixLabel->setObjectName(QString::fromUtf8("prefixLabel"));
        sizePolicy3.setHeightForWidth(prefixLabel->sizePolicy().hasHeightForWidth());
        prefixLabel->setSizePolicy(sizePolicy3);
        prefixLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(prefixLabel, 0, 0, 1, 1);

        lpnBatchModeCheckbox = new QCheckBox(labelSettingsTab);
        lpnBatchModeCheckbox->setObjectName(QString::fromUtf8("lpnBatchModeCheckbox"));

        SettingsLayout->addWidget(lpnBatchModeCheckbox, 4, 3, 1, 1);

        lpnBatchModeLabel = new QLabel(labelSettingsTab);
        lpnBatchModeLabel->setObjectName(QString::fromUtf8("lpnBatchModeLabel"));

        SettingsLayout->addWidget(lpnBatchModeLabel, 4, 2, 1, 1);


        gridLayout_3->addLayout(SettingsLayout, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_3->addItem(horizontalSpacer_2, 0, 1, 1, 1);

        tabWidget->addTab(labelSettingsTab, QString());
        generalSettingsTab = new QWidget();
        generalSettingsTab->setObjectName(QString::fromUtf8("generalSettingsTab"));
        gridLayoutWidget = new QWidget(generalSettingsTab);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(9, 9, 401, 131));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        minimizeToSysTrayLabel = new QLabel(gridLayoutWidget);
        minimizeToSysTrayLabel->setObjectName(QString::fromUtf8("minimizeToSysTrayLabel"));
        minimizeToSysTrayLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(minimizeToSysTrayLabel, 3, 1, 1, 1);

        enableSysTrayCheckbox = new QCheckBox(gridLayoutWidget);
        enableSysTrayCheckbox->setObjectName(QString::fromUtf8("enableSysTrayCheckbox"));

        gridLayout->addWidget(enableSysTrayCheckbox, 2, 2, 1, 1);

        startMinimizedCheckbox = new QCheckBox(gridLayoutWidget);
        startMinimizedCheckbox->setObjectName(QString::fromUtf8("startMinimizedCheckbox"));

        gridLayout->addWidget(startMinimizedCheckbox, 1, 2, 1, 1);

        sysTrayNotificationsCheckbox = new QCheckBox(gridLayoutWidget);
        sysTrayNotificationsCheckbox->setObjectName(QString::fromUtf8("sysTrayNotificationsCheckbox"));

        gridLayout->addWidget(sysTrayNotificationsCheckbox, 5, 2, 1, 1);

        sysTrayNotificationsLabel = new QLabel(gridLayoutWidget);
        sysTrayNotificationsLabel->setObjectName(QString::fromUtf8("sysTrayNotificationsLabel"));
        sysTrayNotificationsLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(sysTrayNotificationsLabel, 5, 1, 1, 1);

        minimizeToSysTrayCheckbox = new QCheckBox(gridLayoutWidget);
        minimizeToSysTrayCheckbox->setObjectName(QString::fromUtf8("minimizeToSysTrayCheckbox"));

        gridLayout->addWidget(minimizeToSysTrayCheckbox, 3, 2, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 6, 1, 1, 1);

        startMinimizedLabel = new QLabel(gridLayoutWidget);
        startMinimizedLabel->setObjectName(QString::fromUtf8("startMinimizedLabel"));
        startMinimizedLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(startMinimizedLabel, 1, 1, 1, 1);

        enableSysTrayLabel = new QLabel(gridLayoutWidget);
        enableSysTrayLabel->setObjectName(QString::fromUtf8("enableSysTrayLabel"));
        enableSysTrayLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout->addWidget(enableSysTrayLabel, 2, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 3, 1, 1);

        tabWidget->addTab(generalSettingsTab, QString());
        advancedSettingsTab = new QWidget();
        advancedSettingsTab->setObjectName(QString::fromUtf8("advancedSettingsTab"));
        gridLayout_2 = new QGridLayout(advancedSettingsTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        wsPortSpinbox = new QSpinBox(advancedSettingsTab);
        wsPortSpinbox->setObjectName(QString::fromUtf8("wsPortSpinbox"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(wsPortSpinbox->sizePolicy().hasHeightForWidth());
        wsPortSpinbox->setSizePolicy(sizePolicy4);
        wsPortSpinbox->setMinimumSize(QSize(0, 20));
        wsPortSpinbox->setMaximum(65535);

        horizontalLayout_2->addWidget(wsPortSpinbox);

        wsServerCheckbox = new QCheckBox(advancedSettingsTab);
        wsServerCheckbox->setObjectName(QString::fromUtf8("wsServerCheckbox"));
        wsServerCheckbox->setEnabled(false);
        wsServerCheckbox->setChecked(true);
        wsServerCheckbox->setTristate(false);

        horizontalLayout_2->addWidget(wsServerCheckbox);

        listenPortLabel = new QLabel(advancedSettingsTab);
        listenPortLabel->setObjectName(QString::fromUtf8("listenPortLabel"));
        listenPortLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(listenPortLabel);

        listenPortSpinbox = new QSpinBox(advancedSettingsTab);
        listenPortSpinbox->setObjectName(QString::fromUtf8("listenPortSpinbox"));
        sizePolicy4.setHeightForWidth(listenPortSpinbox->sizePolicy().hasHeightForWidth());
        listenPortSpinbox->setSizePolicy(sizePolicy4);
        listenPortSpinbox->setMinimumSize(QSize(0, 20));
        listenPortSpinbox->setMaximum(65535);

        horizontalLayout_2->addWidget(listenPortSpinbox);

        skuServerCheckbox = new QCheckBox(advancedSettingsTab);
        skuServerCheckbox->setObjectName(QString::fromUtf8("skuServerCheckbox"));
        skuServerCheckbox->setEnabled(false);

        horizontalLayout_2->addWidget(skuServerCheckbox);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        printCommandLineEdit = new QLineEdit(advancedSettingsTab);
        printCommandLineEdit->setObjectName(QString::fromUtf8("printCommandLineEdit"));

        horizontalLayout_5->addWidget(printCommandLineEdit);

        printCommandCheckbox = new QCheckBox(advancedSettingsTab);
        printCommandCheckbox->setObjectName(QString::fromUtf8("printCommandCheckbox"));
        printCommandCheckbox->setEnabled(false);
        printCommandCheckbox->setChecked(true);

        horizontalLayout_5->addWidget(printCommandCheckbox);


        gridLayout_2->addLayout(horizontalLayout_5, 4, 1, 1, 1);

        label = new QLabel(advancedSettingsTab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(label, 6, 0, 1, 1);

        printServerLineEdit = new QLineEdit(advancedSettingsTab);
        printServerLineEdit->setObjectName(QString::fromUtf8("printServerLineEdit"));
        printServerLineEdit->setEnabled(true);

        gridLayout_2->addWidget(printServerLineEdit, 2, 1, 1, 1);

        printCommandLabel = new QLabel(advancedSettingsTab);
        printCommandLabel->setObjectName(QString::fromUtf8("printCommandLabel"));
        printCommandLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(printCommandLabel, 4, 0, 1, 1);

        printerNameLabel = new QLabel(advancedSettingsTab);
        printerNameLabel->setObjectName(QString::fromUtf8("printerNameLabel"));
        printerNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(printerNameLabel, 3, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 7, 1, 1, 1);

        printServerLabel = new QLabel(advancedSettingsTab);
        printServerLabel->setObjectName(QString::fromUtf8("printServerLabel"));
        printServerLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(printServerLabel, 2, 0, 1, 1);

        listenPortLabel_2 = new QLabel(advancedSettingsTab);
        listenPortLabel_2->setObjectName(QString::fromUtf8("listenPortLabel_2"));
        listenPortLabel_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(listenPortLabel_2, 1, 0, 1, 1);

        printerNameLineEdit = new QLineEdit(advancedSettingsTab);
        printerNameLineEdit->setObjectName(QString::fromUtf8("printerNameLineEdit"));

        gridLayout_2->addWidget(printerNameLineEdit, 3, 1, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        remoteLineEdit = new QLineEdit(advancedSettingsTab);
        remoteLineEdit->setObjectName(QString::fromUtf8("remoteLineEdit"));
        QSizePolicy sizePolicy5(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(remoteLineEdit->sizePolicy().hasHeightForWidth());
        remoteLineEdit->setSizePolicy(sizePolicy5);
        remoteLineEdit->setClearButtonEnabled(false);

        gridLayout_4->addWidget(remoteLineEdit, 0, 0, 1, 1);

        remoteSyncButton = new QPushButton(advancedSettingsTab);
        remoteSyncButton->setObjectName(QString::fromUtf8("remoteSyncButton"));
        sizePolicy2.setHeightForWidth(remoteSyncButton->sizePolicy().hasHeightForWidth());
        remoteSyncButton->setSizePolicy(sizePolicy2);
        remoteSyncButton->setMaximumSize(QSize(58, 16777215));

        gridLayout_4->addWidget(remoteSyncButton, 0, 1, 1, 1);

        remoteCheckbox = new QCheckBox(advancedSettingsTab);
        remoteCheckbox->setObjectName(QString::fromUtf8("remoteCheckbox"));
        remoteCheckbox->setEnabled(false);
        QSizePolicy sizePolicy6(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy6.setHorizontalStretch(0);
        sizePolicy6.setVerticalStretch(0);
        sizePolicy6.setHeightForWidth(remoteCheckbox->sizePolicy().hasHeightForWidth());
        remoteCheckbox->setSizePolicy(sizePolicy6);
        remoteCheckbox->setMaximumSize(QSize(16777215, 25));
        remoteCheckbox->setLayoutDirection(Qt::LeftToRight);
        remoteCheckbox->setChecked(false);

        gridLayout_4->addWidget(remoteCheckbox, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout_4, 0, 1, 1, 1);

        remoteLabel = new QLabel(advancedSettingsTab);
        remoteLabel->setObjectName(QString::fromUtf8("remoteLabel"));
        QSizePolicy sizePolicy7(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy7.setHorizontalStretch(0);
        sizePolicy7.setVerticalStretch(0);
        sizePolicy7.setHeightForWidth(remoteLabel->sizePolicy().hasHeightForWidth());
        remoteLabel->setSizePolicy(sizePolicy7);
        remoteLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(remoteLabel, 0, 0, 1, 1);

        formatStringLineEdit = new QLineEdit(advancedSettingsTab);
        formatStringLineEdit->setObjectName(QString::fromUtf8("formatStringLineEdit"));

        gridLayout_2->addWidget(formatStringLineEdit, 6, 1, 1, 1);

        tabWidget->addTab(advancedSettingsTab, QString());

        verticalLayout->addWidget(tabWidget, 0, Qt::AlignTop);

        settingsDialogButtons = new QDialogButtonBox(SettingsUI);
        settingsDialogButtons->setObjectName(QString::fromUtf8("settingsDialogButtons"));
        settingsDialogButtons->setEnabled(true);
        sizePolicy.setHeightForWidth(settingsDialogButtons->sizePolicy().hasHeightForWidth());
        settingsDialogButtons->setSizePolicy(sizePolicy);
        settingsDialogButtons->setLayoutDirection(Qt::LeftToRight);
        settingsDialogButtons->setOrientation(Qt::Horizontal);
        settingsDialogButtons->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok|QDialogButtonBox::RestoreDefaults);
        settingsDialogButtons->setCenterButtons(false);

        verticalLayout->addWidget(settingsDialogButtons);


        retranslateUi(SettingsUI);
        QObject::connect(settingsDialogButtons, SIGNAL(accepted()), SettingsUI, SLOT(accept()));
        QObject::connect(settingsDialogButtons, SIGNAL(rejected()), SettingsUI, SLOT(reject()));

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SettingsUI);
    } // setupUi

    void retranslateUi(QDialog *SettingsUI)
    {
        SettingsUI->setWindowTitle(QCoreApplication::translate("SettingsUI", "Settings", nullptr));
        lpnLabel->setText(QCoreApplication::translate("SettingsUI", "Current LPN:", nullptr));
        lpnSetButton->setText(QCoreApplication::translate("SettingsUI", "Set", nullptr));
        salvageLineEdit->setPlaceholderText(QString());
#if QT_CONFIG(tooltip)
        paddingSpinBox->setToolTip(QCoreApplication::translate("SettingsUI", "Pad the LPN to the specified number of digits", nullptr));
#endif // QT_CONFIG(tooltip)
        deletePrefixButton->setText(QCoreApplication::translate("SettingsUI", "Delete", nullptr));
        copyCheckbox->setText(QString());
        copyLabel->setText(QCoreApplication::translate("SettingsUI", "Copy to clipboard:", nullptr));
        addPrefixButton->setText(QCoreApplication::translate("SettingsUI", "Add", nullptr));
        salvageLabel->setText(QCoreApplication::translate("SettingsUI", "Salvage Label:", nullptr));
        lpnSpinBox->setPrefix(QString());
        paddingLabel->setText(QCoreApplication::translate("SettingsUI", "LPN Padding:", nullptr));
        lpnFetchButton->setText(QCoreApplication::translate("SettingsUI", "Fetch", nullptr));
        prefixLabel->setText(QCoreApplication::translate("SettingsUI", "Label Prefix:", nullptr));
        lpnBatchModeCheckbox->setText(QString());
        lpnBatchModeLabel->setText(QCoreApplication::translate("SettingsUI", "Batch Mode", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(labelSettingsTab), QCoreApplication::translate("SettingsUI", "Labels", nullptr));
        minimizeToSysTrayLabel->setText(QCoreApplication::translate("SettingsUI", "Minimize to system tray", nullptr));
        enableSysTrayCheckbox->setText(QString());
        startMinimizedCheckbox->setText(QString());
        sysTrayNotificationsCheckbox->setText(QString());
        sysTrayNotificationsLabel->setText(QCoreApplication::translate("SettingsUI", "System tray notifications", nullptr));
        minimizeToSysTrayCheckbox->setText(QString());
        startMinimizedLabel->setText(QCoreApplication::translate("SettingsUI", "Start minimized", nullptr));
        enableSysTrayLabel->setText(QCoreApplication::translate("SettingsUI", "Enable system tray icon", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(generalSettingsTab), QCoreApplication::translate("SettingsUI", "General", nullptr));
#if QT_CONFIG(tooltip)
        wsServerCheckbox->setToolTip(QCoreApplication::translate("SettingsUI", "Fetch SKU from LPN", nullptr));
#endif // QT_CONFIG(tooltip)
        wsServerCheckbox->setText(QString());
        listenPortLabel->setText(QCoreApplication::translate("SettingsUI", "Listen Port:", nullptr));
#if QT_CONFIG(tooltip)
        skuServerCheckbox->setToolTip(QCoreApplication::translate("SettingsUI", "Fetch SKU from LPN", nullptr));
#endif // QT_CONFIG(tooltip)
        skuServerCheckbox->setText(QString());
#if QT_CONFIG(tooltip)
        printCommandCheckbox->setToolTip(QCoreApplication::translate("SettingsUI", "Use custom print command", nullptr));
#endif // QT_CONFIG(tooltip)
        printCommandCheckbox->setText(QString());
        label->setText(QCoreApplication::translate("SettingsUI", "Format String:", nullptr));
        printServerLineEdit->setPlaceholderText(QString());
        printCommandLabel->setText(QCoreApplication::translate("SettingsUI", "Print Command:", nullptr));
        printerNameLabel->setText(QCoreApplication::translate("SettingsUI", "Printer Name:", nullptr));
        printServerLabel->setText(QCoreApplication::translate("SettingsUI", "Print Server:", nullptr));
        listenPortLabel_2->setText(QCoreApplication::translate("SettingsUI", "WebSocket:", nullptr));
        remoteLineEdit->setPlaceholderText(QString());
#if QT_CONFIG(tooltip)
        remoteSyncButton->setToolTip(QCoreApplication::translate("SettingsUI", "Send local data to server", nullptr));
#endif // QT_CONFIG(tooltip)
        remoteSyncButton->setText(QCoreApplication::translate("SettingsUI", "Push", nullptr));
#if QT_CONFIG(tooltip)
        remoteCheckbox->setToolTip(QCoreApplication::translate("SettingsUI", "Enable remote sync", nullptr));
#endif // QT_CONFIG(tooltip)
        remoteCheckbox->setText(QString());
        remoteLabel->setText(QCoreApplication::translate("SettingsUI", "Sync Server:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(advancedSettingsTab), QCoreApplication::translate("SettingsUI", "Advanced", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsUI: public Ui_SettingsUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
