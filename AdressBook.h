#ifndef ADRESSBOOK_H
#define ADRESSBOOK_H

#include <QMainWindow>

#include "Entry.h"

class QStringListModel;

class AdressBookEntry;

namespace Ui {
	class AdressBook;
}

class AdressBook : public QMainWindow
{
	Q_OBJECT

public:
	explicit AdressBook(QWidget *parent = nullptr);
	~AdressBook();

public slots:
	void addEntry();
	void removeSelectedEntry();
	void loadEntryData(const QModelIndex &index);
	void saveCurrentEntryData(const Entry &entry);

private:
	Ui::AdressBook *ui;
	AdressBookEntry *m_entryEditForm = nullptr;
	QVector<Entry> m_entries;
	QStringListModel *m_model = nullptr;
};

#endif // ADRESSBOOK_H
