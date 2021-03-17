#include "sdlqtmerge.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SdlQtMerge w;
    w.show();
    return a.exec();
}
