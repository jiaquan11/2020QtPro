/********************************************************************************
** Form generated from reading UI file 'qvs.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QVS_H
#define UI_QVS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QVSClass
{
public:

    void setupUi(QWidget *QVSClass)
    {
        if (QVSClass->objectName().isEmpty())
            QVSClass->setObjectName(QStringLiteral("QVSClass"));
        QVSClass->resize(600, 400);

        retranslateUi(QVSClass);

        QMetaObject::connectSlotsByName(QVSClass);
    } // setupUi

    void retranslateUi(QWidget *QVSClass)
    {
        QVSClass->setWindowTitle(QApplication::translate("QVSClass", "QVS", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class QVSClass: public Ui_QVSClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QVS_H
