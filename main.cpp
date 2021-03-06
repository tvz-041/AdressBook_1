#include <QApplication>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>

#include "AdressBook.h"
#include "AdressBookEntry.h"

QJsonObject loadJsonFromFile(const QString &filename)
{
	QFile file(filename);
	QJsonObject json;

	if (file.open(QFile::ReadOnly)) {
		QJsonDocument documentfile = QJsonDocument::fromJson(file.readAll());
		file.close();
		json = documentfile.object();
	}

	return json;
}

void saveJsonToFile(const QString &filename, const QJsonObject &json)
{
	QFile file(filename);

	if (file.open(QFile::WriteOnly)) {
		QJsonDocument document(json);
		file.write(document.toJson());
		file.close();
	}
}

void saveAdressBookEntryToFile(const QJsonObject &entryProperties)
{
	saveJsonToFile("AdressBookEntry.json", entryProperties);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

//	AdressBookEntry entry;

//	entry.fromJson(loadJsonFromFile("AdressBookEntry.json"));
//	QObject::connect(&entry, &AdressBookEntry::propertiesChanged, &saveAdressBookEntryToFile);

//	entry.show();

	AdressBook adressBook;
	adressBook.show();

	return a.exec();
}
