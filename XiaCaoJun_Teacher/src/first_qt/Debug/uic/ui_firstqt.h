/********************************************************************************
** Form generated from reading UI file 'firstqt.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRSTQT_H
#define UI_FIRSTQT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstQtClass
{
public:

    void setupUi(QWidget *FirstQtClass)
    {
        if (FirstQtClass->objectName().isEmpty())
            FirstQtClass->setObjectName(QString::fromUtf8("FirstQtClass"));
        FirstQtClass->resize(600, 400);

        retranslateUi(FirstQtClass);

        QMetaObject::connectSlotsByName(FirstQtClass);
    } // setupUi

    void retranslateUi(QWidget *FirstQtClass)
    {
        FirstQtClass->setWindowTitle(QCoreApplication::translate("FirstQtClass", "FirstQt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstQtClass: public Ui_FirstQtClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRSTQT_H
