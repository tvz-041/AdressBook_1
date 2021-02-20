#include "AdressBookEntry.h"

#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	AdressBookEntry w;
	w.show();
	return a.exec();
}
