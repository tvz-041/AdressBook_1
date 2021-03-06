#include <QDebug>
#include <QJsonObject>

#include "Entry.h"

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

void AdressBookEntry::fromJson(const QJsonObject &properties)
{
	ui->plainTextEdit_other->blockSignals(true);

	ui->lineEdit_firstName->setText(properties["firstName"].toString());
	ui->lineEdit_secondName->setText(properties["secondName"].toString());
	ui->lineEdit_thirdName->setText(properties["thirdName"].toString());
	ui->lineEdit_adress->setText(properties["adress"].toString());
	ui->lineEdit_homePhoneNumber->setText(properties["homePhoneNumber"].toString());
	ui->lineEdit_mobilePhoneNumber->setText(properties["mobilePhoneNumber"].toString());
	ui->plainTextEdit_other->setPlainText(properties["other"].toString());

	ui->plainTextEdit_other->blockSignals(false);

	if (m_hasUnsavedChanges) {
		ui->pushButton_save->setText("Сохранить");
		m_hasUnsavedChanges = false;
	}
}

QJsonObject AdressBookEntry::toJson() const
{
	QJsonObject properties;

	properties["firstName"]			= ui->lineEdit_firstName->text();
	properties["secondName"]		= ui->lineEdit_secondName->text();
	properties["thirdName"]			= ui->lineEdit_thirdName->text();
	properties["adress"]			= ui->lineEdit_adress->text();
	properties["homePhoneNumber"]	= ui->lineEdit_homePhoneNumber->text();
	properties["mobilePhoneNumber"] = ui->lineEdit_mobilePhoneNumber->text();
	properties["other"]				= ui->plainTextEdit_other->toPlainText();

	return properties;
}

void AdressBookEntry::fromEntry(const Entry &entry)
{
	ui->plainTextEdit_other->blockSignals(true);

	ui->lineEdit_firstName->setText(entry.firstName);
	ui->lineEdit_secondName->setText(entry.secondName);
	ui->lineEdit_thirdName->setText(entry.thirdName);
	ui->lineEdit_adress->setText(entry.adress);
	ui->lineEdit_homePhoneNumber->setText(entry.homePhoneNumber);
	ui->lineEdit_mobilePhoneNumber->setText(entry.mobilePhoneNumber);
	ui->plainTextEdit_other->setPlainText(entry.other);

	ui->plainTextEdit_other->blockSignals(false);

	if (m_hasUnsavedChanges) {
		ui->pushButton_save->setText("Сохранить");
		m_hasUnsavedChanges = false;
	}
}

Entry AdressBookEntry::toEntry() const
{
	Entry entry;

	entry.firstName			= ui->lineEdit_firstName->text();
	entry.secondName		= ui->lineEdit_secondName->text();
	entry.thirdName			= ui->lineEdit_thirdName->text();
	entry.adress			= ui->lineEdit_adress->text();
	entry.homePhoneNumber	= ui->lineEdit_homePhoneNumber->text();
	entry.mobilePhoneNumber = ui->lineEdit_mobilePhoneNumber->text();
	entry.other				= ui->plainTextEdit_other->toPlainText();

	return entry;
}

void AdressBookEntry::save()
{
	if (m_hasUnsavedChanges) {
		ui->pushButton_save->setText("Сохранить");
		emit entryChanged(toEntry());
		m_hasUnsavedChanges = false;
	}
}

void AdressBookEntry::markUnsavedChanges()
{
	if (!m_hasUnsavedChanges) {
		ui->pushButton_save->setText("Сохранить*");
		m_hasUnsavedChanges = true;
	}
}
