#ifndef ADRESSBOOKENTRY_H
#define ADRESSBOOKENTRY_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class AdressBookEntry; }
QT_END_NAMESPACE

class AdressBookEntry : public QWidget
{
	Q_OBJECT

public:
	AdressBookEntry(QWidget *parent = nullptr);
	~AdressBookEntry();

private:
	Ui::AdressBookEntry *ui;
};
#endif // ADRESSBOOKENTRY_H
