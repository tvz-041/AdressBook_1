#include "EntriesModel.h"

EntriesModel::EntriesModel(QObject *parent) :
	QAbstractListModel(parent)
{

}

QVariant EntriesModel::data(const QModelIndex &index, int role) const
{
	switch (role) {
		case Qt::DisplayRole:
			return m_entries[index.row()].fullName();
		break;
	}

	return QVariant();
}

int	EntriesModel::rowCount(const QModelIndex &/*parent*/) const
{
	return m_entries.count();
}

bool EntriesModel::removeRows(int row, int count, const QModelIndex &/*parent*/)
{
	if (row > -1 && (row + count - 1) < m_entries.count()) {
		beginRemoveRows(QModelIndex(), row, row + count - 1);
		m_entries.remove(row, count);
		endRemoveRows();
		return true;
	}

	return false;
}

const Entry &EntriesModel::at(const QModelIndex &index)
{
	return m_entries[index.row()];
}

void EntriesModel::append(const Entry &entry)
{
	beginInsertRows(QModelIndex(), m_entries.count(), m_entries.count());
	m_entries.append(entry);
	endInsertRows();
}

void EntriesModel::replace(const QModelIndex &index, const Entry &entry)
{
	m_entries[index.row()] = entry;
	emit dataChanged(index, index);
}
