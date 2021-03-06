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
}

AdressBook::~AdressBook()
{
	delete ui;
}
