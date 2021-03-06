#ifndef ENTRY_H
#define ENTRY_H

#include <QString>

struct Entry
{
	QString firstName;
	QString secondName;
	QString thirdName;

	QString adress;
	QString homePhoneNumber;
	QString mobilePhoneNumber;
	QString other;

	QString fullName() const
	{
		return secondName + ' ' + firstName + ' ' + thirdName;
	}
};

#endif // ENTRY_H
