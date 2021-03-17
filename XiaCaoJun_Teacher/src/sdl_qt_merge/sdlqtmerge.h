#pragma once

#include <QtWidgets/QWidget>
#include "ui_sdlqtmerge.h"

class SdlQtMerge : public QWidget
{
    Q_OBJECT

public:
    SdlQtMerge(QWidget *parent = Q_NULLPTR);
    void timerEvent(QTimerEvent* ev) override;

private:
    Ui::SdlQtMergeClass ui;
};
