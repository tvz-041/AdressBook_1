#include <QModelIndex>
#include <QStringListModel>

#include "AdressBookEntry.h"

#include "AdressBook.h"
#include "ui_AdressBook.h"

AdressBook::AdressBook(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AdressBook)
{
	ui->setupUi(this);

	m_entryEditForm = new AdressBookEntry(ui->centralwidget);
	ui->mainLayout->addWidget(m_entryEditForm);
	m_model = new QStringListModel(this);
	ui->listView->setModel(m_model);

	connect(ui->pushButton_add, &QPushButton::clicked, this, &AdressBook::addEntry);
	connect(ui->pushButton_remove, &QPushButton::clicked, this, &AdressBook::removeSelectedEntry);
	connect(ui->listView->selectionModel(), &QItemSelectionModel::currentRowChanged,
			this, &AdressBook::loadEntryData);
	connect(m_entryEditForm, &AdressBookEntry::entryChanged, this, &AdressBook::saveCurrentEntryData);
}

AdressBook::~AdressBook()
{
	delete ui;
}

void AdressBook::addEntry()
{
	Entry entry;
	entry.firstName = "Имя";
	entry.secondName = "Фамилия";
	m_entries.append(entry);
	int newRowIndex = m_model->rowCount();
	m_model->insertRow(newRowIndex);
	m_model->setData(m_model->index(newRowIndex), entry.fullName());
}

void AdressBook::removeSelectedEntry()
{
	QModelIndex currentIndex = ui->listView->selectionModel()->currentIndex();

	if (currentIndex.isValid()) {
		m_entries.remove(currentIndex.row());
		m_model->removeRow(currentIndex.row());
	}
}

void AdressBook::loadEntryData(const QModelIndex &index)
{
	if (index.row() > -1 && index.row() < m_entries.count()) {
		m_entryEditForm->fromEntry(m_entries[index.row()]);
	}
}

void AdressBook::saveCurrentEntryData(const Entry &entry)
{
	QModelIndex currentIndex = ui->listView->selectionModel()->currentIndex();

	if (currentIndex.isValid()) {
		m_entries[currentIndex.row()] = entry;
		m_model->setData(currentIndex, entry.fullName());
	}
}
