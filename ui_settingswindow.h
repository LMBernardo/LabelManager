/********************************************************************************
** Form generated from reading UI file 'settingswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
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
    QSpacerItem *verticalSpacer;
    QWidget *advancedSettingsTab;
    QGridLayout *gridLayout_2;
    QLabel *printServerLabel;
    QLineEdit *printServerLineEdit;
    QLabel *remoteLabel;
    QLineEdit *printerNameLineEdit;
    QHBoxLayout *horizontalLayout_5;
    QLineEdit *printCommandLineEdit;
    QCheckBox *printCommandCheckbox;
    QLabel *printCommandLabel;
    QHBoxLayout *horizontalLayout;
    QLineEdit *remoteLineEdit;
    QPushButton *remoteSyncButton;
    QCheckBox *remoteCheckbox;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *skuServerLineEdit;
    QCheckBox *skuServerCheckbox;
    QLabel *printerNameLabel;
    QLabel *skuServerLabel;
    QSpacerItem *verticalSpacer_2;
    QDialogButtonBox *settingsDialogButtons;

    void setupUi(QDialog *SettingsUI)
    {
        if (SettingsUI->objectName().isEmpty())
            SettingsUI->setObjectName(QString::fromUtf8("SettingsUI"));
        SettingsUI->setWindowModality(Qt::ApplicationModal);
        SettingsUI->resize(415, 225);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingsUI->sizePolicy().hasHeightForWidth());
        SettingsUI->setSizePolicy(sizePolicy);
        SettingsUI->setMaximumSize(QSize(415, 225));
        SettingsUI->setModal(true);
        verticalLayout = new QVBoxLayout(SettingsUI);
        verticalLayout->setSpacing(5);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(5, -1, -1, 7);
        tabWidget = new QTabWidget(SettingsUI);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(tabWidget->sizePolicy().hasHeightForWidth());
        tabWidget->setSizePolicy(sizePolicy1);
        tabWidget->setMaximumSize(QSize(16777215, 184));
        labelSettingsTab = new QWidget();
        labelSettingsTab->setObjectName(QString::fromUtf8("labelSettingsTab"));
        labelSettingsTab->setMaximumSize(QSize(16777215, 156));
        gridLayout_3 = new QGridLayout(labelSettingsTab);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        SettingsLayout = new QGridLayout();
        SettingsLayout->setObjectName(QString::fromUtf8("SettingsLayout"));
        SettingsLayout->setContentsMargins(5, -1, 5, -1);
        lpnLabel = new QLabel(labelSettingsTab);
        lpnLabel->setObjectName(QString::fromUtf8("lpnLabel"));
        sizePolicy.setHeightForWidth(lpnLabel->sizePolicy().hasHeightForWidth());
        lpnLabel->setSizePolicy(sizePolicy);
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
        salvageLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(salvageLabel, 3, 0, 1, 1);

        lpnSpinBox = new QSpinBox(labelSettingsTab);
        lpnSpinBox->setObjectName(QString::fromUtf8("lpnSpinBox"));
        sizePolicy.setHeightForWidth(lpnSpinBox->sizePolicy().hasHeightForWidth());
        lpnSpinBox->setSizePolicy(sizePolicy);
        lpnSpinBox->setMinimumSize(QSize(110, 0));
        lpnSpinBox->setMaximumSize(QSize(115, 16777215));
        lpnSpinBox->setMaximum(99999999);
        lpnSpinBox->setValue(0);

        SettingsLayout->addWidget(lpnSpinBox, 1, 1, 1, 1);

        paddingLabel = new QLabel(labelSettingsTab);
        paddingLabel->setObjectName(QString::fromUtf8("paddingLabel"));
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
        prefixLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        SettingsLayout->addWidget(prefixLabel, 0, 0, 1, 1);


        gridLayout_3->addLayout(SettingsLayout, 0, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 1, 0, 1, 1);

        tabWidget->addTab(labelSettingsTab, QString());
        advancedSettingsTab = new QWidget();
        advancedSettingsTab->setObjectName(QString::fromUtf8("advancedSettingsTab"));
        gridLayout_2 = new QGridLayout(advancedSettingsTab);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        printServerLabel = new QLabel(advancedSettingsTab);
        printServerLabel->setObjectName(QString::fromUtf8("printServerLabel"));
        printServerLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(printServerLabel, 2, 0, 1, 1);

        printServerLineEdit = new QLineEdit(advancedSettingsTab);
        printServerLineEdit->setObjectName(QString::fromUtf8("printServerLineEdit"));
        printServerLineEdit->setEnabled(false);

        gridLayout_2->addWidget(printServerLineEdit, 2, 1, 1, 1);

        remoteLabel = new QLabel(advancedSettingsTab);
        remoteLabel->setObjectName(QString::fromUtf8("remoteLabel"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Minimum);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(remoteLabel->sizePolicy().hasHeightForWidth());
        remoteLabel->setSizePolicy(sizePolicy3);
        remoteLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(remoteLabel, 0, 0, 1, 1);

        printerNameLineEdit = new QLineEdit(advancedSettingsTab);
        printerNameLineEdit->setObjectName(QString::fromUtf8("printerNameLineEdit"));

        gridLayout_2->addWidget(printerNameLineEdit, 3, 1, 1, 1);

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

        printCommandLabel = new QLabel(advancedSettingsTab);
        printCommandLabel->setObjectName(QString::fromUtf8("printCommandLabel"));
        printCommandLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(printCommandLabel, 4, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        remoteLineEdit = new QLineEdit(advancedSettingsTab);
        remoteLineEdit->setObjectName(QString::fromUtf8("remoteLineEdit"));
        QSizePolicy sizePolicy4(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(remoteLineEdit->sizePolicy().hasHeightForWidth());
        remoteLineEdit->setSizePolicy(sizePolicy4);
        remoteLineEdit->setClearButtonEnabled(false);

        horizontalLayout->addWidget(remoteLineEdit);

        remoteSyncButton = new QPushButton(advancedSettingsTab);
        remoteSyncButton->setObjectName(QString::fromUtf8("remoteSyncButton"));
        sizePolicy2.setHeightForWidth(remoteSyncButton->sizePolicy().hasHeightForWidth());
        remoteSyncButton->setSizePolicy(sizePolicy2);
        remoteSyncButton->setMaximumSize(QSize(58, 16777215));

        horizontalLayout->addWidget(remoteSyncButton);

        remoteCheckbox = new QCheckBox(advancedSettingsTab);
        remoteCheckbox->setObjectName(QString::fromUtf8("remoteCheckbox"));
        remoteCheckbox->setEnabled(false);
        QSizePolicy sizePolicy5(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(remoteCheckbox->sizePolicy().hasHeightForWidth());
        remoteCheckbox->setSizePolicy(sizePolicy5);
        remoteCheckbox->setMaximumSize(QSize(16777215, 25));
        remoteCheckbox->setLayoutDirection(Qt::LeftToRight);
        remoteCheckbox->setChecked(false);

        horizontalLayout->addWidget(remoteCheckbox);


        gridLayout_2->addLayout(horizontalLayout, 0, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        skuServerLineEdit = new QLineEdit(advancedSettingsTab);
        skuServerLineEdit->setObjectName(QString::fromUtf8("skuServerLineEdit"));
        skuServerLineEdit->setEnabled(true);

        horizontalLayout_2->addWidget(skuServerLineEdit);

        skuServerCheckbox = new QCheckBox(advancedSettingsTab);
        skuServerCheckbox->setObjectName(QString::fromUtf8("skuServerCheckbox"));
        skuServerCheckbox->setEnabled(false);

        horizontalLayout_2->addWidget(skuServerCheckbox);


        gridLayout_2->addLayout(horizontalLayout_2, 1, 1, 1, 1);

        printerNameLabel = new QLabel(advancedSettingsTab);
        printerNameLabel->setObjectName(QString::fromUtf8("printerNameLabel"));
        printerNameLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(printerNameLabel, 3, 0, 1, 1);

        skuServerLabel = new QLabel(advancedSettingsTab);
        skuServerLabel->setObjectName(QString::fromUtf8("skuServerLabel"));
        skuServerLabel->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        gridLayout_2->addWidget(skuServerLabel, 1, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer_2, 5, 1, 1, 1);

        tabWidget->addTab(advancedSettingsTab, QString());

        verticalLayout->addWidget(tabWidget);

        settingsDialogButtons = new QDialogButtonBox(SettingsUI);
        settingsDialogButtons->setObjectName(QString::fromUtf8("settingsDialogButtons"));
        settingsDialogButtons->setEnabled(true);
        sizePolicy1.setHeightForWidth(settingsDialogButtons->sizePolicy().hasHeightForWidth());
        settingsDialogButtons->setSizePolicy(sizePolicy1);
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
        SettingsUI->setWindowTitle(QApplication::translate("SettingsUI", "Settings", nullptr));
        lpnLabel->setText(QApplication::translate("SettingsUI", "Current LPN:", nullptr));
        lpnSetButton->setText(QApplication::translate("SettingsUI", "Set", nullptr));
        salvageLineEdit->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        paddingSpinBox->setToolTip(QApplication::translate("SettingsUI", "Pad the LPN to the specified number of digits", nullptr));
#endif // QT_NO_TOOLTIP
        deletePrefixButton->setText(QApplication::translate("SettingsUI", "Delete", nullptr));
        copyCheckbox->setText(QString());
        copyLabel->setText(QApplication::translate("SettingsUI", "Copy to clipboard:", nullptr));
        addPrefixButton->setText(QApplication::translate("SettingsUI", "Add", nullptr));
        salvageLabel->setText(QApplication::translate("SettingsUI", "Salvage Label:", nullptr));
        lpnSpinBox->setPrefix(QString());
        paddingLabel->setText(QApplication::translate("SettingsUI", "LPN Padding:", nullptr));
        lpnFetchButton->setText(QApplication::translate("SettingsUI", "Fetch", nullptr));
        prefixLabel->setText(QApplication::translate("SettingsUI", "Label Prefix:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(labelSettingsTab), QApplication::translate("SettingsUI", "Labels", nullptr));
        printServerLabel->setText(QApplication::translate("SettingsUI", "Print Server:", nullptr));
        printServerLineEdit->setPlaceholderText(QString());
        remoteLabel->setText(QApplication::translate("SettingsUI", "Sync Server:", nullptr));
#ifndef QT_NO_TOOLTIP
        printCommandCheckbox->setToolTip(QApplication::translate("SettingsUI", "Use custom print command", nullptr));
#endif // QT_NO_TOOLTIP
        printCommandCheckbox->setText(QString());
        printCommandLabel->setText(QApplication::translate("SettingsUI", "Print Command:", nullptr));
        remoteLineEdit->setPlaceholderText(QString());
#ifndef QT_NO_TOOLTIP
        remoteSyncButton->setToolTip(QApplication::translate("SettingsUI", "Send local data to server", nullptr));
#endif // QT_NO_TOOLTIP
        remoteSyncButton->setText(QApplication::translate("SettingsUI", "Push", nullptr));
#ifndef QT_NO_TOOLTIP
        remoteCheckbox->setToolTip(QApplication::translate("SettingsUI", "Enable remote sync", nullptr));
#endif // QT_NO_TOOLTIP
        remoteCheckbox->setText(QString());
#ifndef QT_NO_TOOLTIP
        skuServerCheckbox->setToolTip(QApplication::translate("SettingsUI", "Fetch SKU from LPN", nullptr));
#endif // QT_NO_TOOLTIP
        skuServerCheckbox->setText(QString());
        printerNameLabel->setText(QApplication::translate("SettingsUI", "Printer Name:", nullptr));
        skuServerLabel->setText(QApplication::translate("SettingsUI", "SKU Server:", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(advancedSettingsTab), QApplication::translate("SettingsUI", "Advanced", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingsUI: public Ui_SettingsUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGSWINDOW_H
