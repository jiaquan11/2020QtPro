#pragma once

#include <QtWidgets/QWidget>
#include "ui_testrgb.h"

class TestRGB : public QWidget
{
    Q_OBJECT

public:
    TestRGB(QWidget *parent = Q_NULLPTR);

    //���ػ��ƻ��溯��
    void paintEvent(QPaintEvent* ev) override;

private:
    Ui::TestRGBClass ui;
};
