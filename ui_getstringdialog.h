/********************************************************************************
** Form generated from reading UI file 'getstringdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSTRINGDIALOG_H
#define UI_GETSTRINGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_getStringDialog
{
public:
    QFormLayout *formLayout;
    QLabel *getStringLabel;
    QLineEdit *getStringLineEdit;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *getStringDialog)
    {
        if (getStringDialog->objectName().isEmpty())
            getStringDialog->setObjectName(QString::fromUtf8("getStringDialog"));
        getStringDialog->resize(195, 74);
        formLayout = new QFormLayout(getStringDialog);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        getStringLabel = new QLabel(getStringDialog);
        getStringLabel->setObjectName(QString::fromUtf8("getStringLabel"));

        formLayout->setWidget(0, QFormLayout::LabelRole, getStringLabel);

        getStringLineEdit = new QLineEdit(getStringDialog);
        getStringLineEdit->setObjectName(QString::fromUtf8("getStringLineEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(getStringLineEdit->sizePolicy().hasHeightForWidth());
        getStringLineEdit->setSizePolicy(sizePolicy);

        formLayout->setWidget(0, QFormLayout::FieldRole, getStringLineEdit);

        buttonBox = new QDialogButtonBox(getStringDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(1, QFormLayout::SpanningRole, buttonBox);


        retranslateUi(getStringDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), getStringDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), getStringDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(getStringDialog);
    } // setupUi

    void retranslateUi(QDialog *getStringDialog)
    {
        getStringDialog->setWindowTitle(QApplication::translate("getStringDialog", "Dialog", nullptr));
        getStringLabel->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class getStringDialog: public Ui_getStringDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSTRINGDIALOG_H
