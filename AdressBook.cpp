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

	connect(ui->pushButton_add, &QPushButton::clicked, this, &AdressBook::addEntry);
	connect(ui->pushButton_remove, &QPushButton::clicked, this, &AdressBook::removeSelectedEntry);
	connect(ui->listWidget, &QListWidget::currentRowChanged, this, &AdressBook::loadEntryData);
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
	ui->listWidget->addItem(entry.fullName());
}

void AdressBook::removeSelectedEntry()
{
	QListWidgetItem *currentItem = ui->listWidget->currentItem();

	if (currentItem != nullptr) {
		m_entries.remove(ui->listWidget->currentRow());
		delete currentItem;
	}
}

void AdressBook::loadEntryData(const int index)
{
	if (index > -1 && index < m_entries.count()) {
		m_entryEditForm->fromEntry(m_entries[index]);
	}
}

void AdressBook::saveCurrentEntryData(const Entry &entry)
{
	int rowIndex = ui->listWidget->currentRow();

	if (rowIndex > -1 && rowIndex < m_entries.count()) {
		m_entries[rowIndex] = entry;
		ui->listWidget->currentItem()->setText(entry.fullName());
	}
}
