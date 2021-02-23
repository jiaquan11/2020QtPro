#pragma once

#include <QtWidgets/QWidget>
#include "ui_qvs.h"

class QVS : public QWidget
{
	Q_OBJECT

public:
	QVS(QWidget *parent = Q_NULLPTR);

private:
	Ui::QVSClass ui;
};
