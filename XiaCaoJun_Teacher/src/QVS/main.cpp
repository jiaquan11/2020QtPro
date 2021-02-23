#include "qvs.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	QVS w;
	w.show();
	return a.exec();
}
