#include "AdressBookEntry.h"
#include "ui_AdressBookEntry.h"

AdressBookEntry::AdressBookEntry(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::AdressBookEntry)
{
	ui->setupUi(this);

	connect(ui->lineEdit_firstName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
	connect(ui->lineEdit_secondName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
	connect(ui->lineEdit_thirdName, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
	connect(ui->lineEdit_adress, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
	connect(ui->lineEdit_homePhoneNumber, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
	connect(ui->lineEdit_mobilePhoneNumber, &QLineEdit::textEdited, this, &AdressBookEntry::markUnsavedChanges);
	connect(ui->plainTextEdit_other, &QPlainTextEdit::textChanged, this, &AdressBookEntry::markUnsavedChanges);

	connect(ui->pushButton_save, &QPushButton::clicked, this, &AdressBookEntry::save);
}

AdressBookEntry::~AdressBookEntry()
{
	delete ui;
}

void AdressBookEntry::save()
{
	ui->pushButton_save->setText("Сохранить");
}

void AdressBookEntry::markUnsavedChanges()
{
	ui->pushButton_save->setText("Сохранить*");
}
