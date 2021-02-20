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

public slots:
	void save();

private slots:
	void markUnsavedChanges();

private:
	Ui::AdressBookEntry *ui;
};
#endif // ADRESSBOOKENTRY_H
