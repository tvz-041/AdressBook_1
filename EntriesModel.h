#ifndef ENTRIESMODEL_H
#define ENTRIESMODEL_H

#include <QAbstractListModel>

#include "Entry.h"

class EntriesModel : public QAbstractListModel
{
public:
	EntriesModel(QObject *parent);

	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	int	rowCount(const QModelIndex &parent = QModelIndex()) const override;
	bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex()) override;

	const Entry &at(const QModelIndex &index);
	void append(const Entry &entry);
	void replace(const QModelIndex &index, const Entry &entry);

private:
	QVector<Entry> m_entries;
};

#endif // ENTRIESMODEL_H
