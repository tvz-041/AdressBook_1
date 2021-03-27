#include <QModelIndex>

#include "AdressBookEntry.h"
#include "EntriesModel.h"

#include "AdressBook.h"
#include "ui_AdressBook.h"

AdressBook::AdressBook(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::AdressBook)
{
	ui->setupUi(this);

	m_entryEditForm = new AdressBookEntry(ui->centralwidget);
	ui->mainLayout->addWidget(m_entryEditForm);
	m_model = new EntriesModel(this);
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
	m_model->append(entry);
}

void AdressBook::removeSelectedEntry()
{
	QModelIndex currentIndex = ui->listView->selectionModel()->currentIndex();

	if (currentIndex.isValid()) {
		m_model->removeRow(currentIndex.row());
	}
}

void AdressBook::loadEntryData(const QModelIndex &index)
{
	if (index.isValid()) {
		m_entryEditForm->fromEntry(m_model->at(index));
	}
}

void AdressBook::saveCurrentEntryData(const Entry &entry)
{
	QModelIndex currentIndex = ui->listView->selectionModel()->currentIndex();

	if (currentIndex.isValid()) {
		m_model->replace(currentIndex, entry);
	}
}
