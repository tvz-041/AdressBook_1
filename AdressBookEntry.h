#ifndef ADRESSBOOKENTRY_H
#define ADRESSBOOKENTRY_H

#include <QWidget>

struct Entry;

QT_BEGIN_NAMESPACE
namespace Ui { class AdressBookEntry; }
QT_END_NAMESPACE

class AdressBookEntry : public QWidget
{
	Q_OBJECT

public:
	AdressBookEntry(QWidget *parent = nullptr);
	~AdressBookEntry();

	void fromJson(const QJsonObject &properties);
	QJsonObject toJson() const;

	void fromEntry(const Entry &entry);
	Entry toEntry() const;

signals:
	void propertiesChanged(const QJsonObject &properties);

public slots:
	void save();

private slots:
	void markUnsavedChanges();

private:
	Ui::AdressBookEntry *ui;

	bool m_hasUnsavedChanges = false;
};
#endif // ADRESSBOOKENTRY_H
