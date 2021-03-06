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
	QList<QListWidgetItem *> selectedItems = ui->listWidget->selectedItems();

	if (!selectedItems.isEmpty()) {
		delete selectedItems.first();
	}
}
