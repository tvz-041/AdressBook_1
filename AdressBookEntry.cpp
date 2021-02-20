#include "AdressBookEntry.h"
#include "ui_AdressBookEntry.h"

AdressBookEntry::AdressBookEntry(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AdressBookEntry)
{
	ui->setupUi(this);
}

AdressBookEntry::~AdressBookEntry()
{
	delete ui;
}

