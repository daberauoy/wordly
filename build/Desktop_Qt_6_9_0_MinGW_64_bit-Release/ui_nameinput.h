/********************************************************************************
** Form generated from reading UI file 'nameinput.ui'
**
** Created by: Qt User Interface Compiler version 6.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NAMEINPUT_H
#define UI_NAMEINPUT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NameInput
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *buttonRU;
    QPushButton *buttonEN;
    QLabel *labelLang;
    QPushButton *buttonOK;

    void setupUi(QDialog *NameInput)
    {
        if (NameInput->objectName().isEmpty())
            NameInput->setObjectName("NameInput");
        NameInput->resize(424, 267);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(NameInput->sizePolicy().hasHeightForWidth());
        NameInput->setSizePolicy(sizePolicy);
        NameInput->setSizeGripEnabled(false);
        lineEdit = new QLineEdit(NameInput);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(10, 70, 261, 51));
        QFont font;
        font.setPointSize(16);
        lineEdit->setFont(font);
        label = new QLabel(NameInput);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 20, 261, 41));
        QFont font1;
        font1.setPointSize(14);
        label->setFont(font1);
        buttonRU = new QPushButton(NameInput);
        buttonRU->setObjectName("buttonRU");
        buttonRU->setGeometry(QRect(10, 190, 81, 61));
        QFont font2;
        font2.setPointSize(20);
        font2.setBold(true);
        font2.setKerning(false);
        buttonRU->setFont(font2);
        buttonRU->setCheckable(true);
        buttonRU->setChecked(true);
        buttonEN = new QPushButton(NameInput);
        buttonEN->setObjectName("buttonEN");
        buttonEN->setGeometry(QRect(90, 190, 81, 61));
        buttonEN->setFont(font2);
        buttonEN->setCheckable(true);
        labelLang = new QLabel(NameInput);
        labelLang->setObjectName("labelLang");
        labelLang->setGeometry(QRect(10, 140, 261, 41));
        labelLang->setFont(font1);
        buttonOK = new QPushButton(NameInput);
        buttonOK->setObjectName("buttonOK");
        buttonOK->setGeometry(QRect(309, 213, 91, 31));

        retranslateUi(NameInput);

        QMetaObject::connectSlotsByName(NameInput);
    } // setupUi

    void retranslateUi(QDialog *NameInput)
    {
        NameInput->setWindowTitle(QCoreApplication::translate("NameInput", "Dialog", nullptr));
        lineEdit->setText(QString());
        label->setText(QCoreApplication::translate("NameInput", "\320\222\320\262\320\265\320\264\320\270\321\202\320\265 \320\270\320\274\321\217:", nullptr));
        buttonRU->setText(QCoreApplication::translate("NameInput", "RU", nullptr));
        buttonEN->setText(QCoreApplication::translate("NameInput", "EN", nullptr));
        labelLang->setText(QCoreApplication::translate("NameInput", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \321\217\320\267\321\213\320\272:", nullptr));
        buttonOK->setText(QCoreApplication::translate("NameInput", "OK", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NameInput: public Ui_NameInput {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NAMEINPUT_H
