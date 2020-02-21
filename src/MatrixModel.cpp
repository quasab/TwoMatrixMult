#include "MatrixModel.h"

MatrixModel::MatrixModel(int _rows, int _columns, QObject *_parent):
    QAbstractTableModel(_parent)
{
    m_matrix = QVector<QVector<double>> (_rows, QVector<double>(_columns));
}

MatrixModel::~MatrixModel()
{
}

int MatrixModel::rowCount(const QModelIndex &/*_parent*/) const
{
    return m_matrix.count();

}

int MatrixModel::columnCount(const QModelIndex &/*_parent*/) const
{
    return m_matrix.at(0).count();
}

QVariant MatrixModel::data(const QModelIndex &_index, int _role) const
{
    if (_index.isValid() && _role == Qt::DisplayRole)
    {
        return m_matrix.at(_index.row()).at(_index.column());
    }

    return QVariant();
}

bool MatrixModel::setData(const QModelIndex &_index,
                          const QVariant &_value,
                          int _role)
{
    if (_index.isValid() && _role == Qt::EditRole)
    {
        bool ok = false;
        double value = _value.toDouble(&ok);

        if (ok)
        {
            m_matrix[_index.row()][_index.column()] = value;

            emit dataChanged(_index, _index);

            return true;
        }
        else
        {
            return false;
        }
    }

    return false;
}

Qt::ItemFlags MatrixModel::flags(const QModelIndex &_index) const
{
    Qt::ItemFlags flags = QAbstractTableModel::flags(_index);

    if (_index.isValid())
    {
        return (flags | Qt::ItemIsEditable);
    }
    else
    {
        return flags;
    }
}

void MatrixModel::rowCountChanged(int _count)
{
    if (_count > rowCount())
    {
        int difference = _count - rowCount();

        beginInsertRows(QModelIndex(), rowCount(), _count - 1);

        for (int i = 0; i < difference; ++i)
        {
           m_matrix.append(QVector<double>(columnCount()));
        }

        endInsertRows();
    }
    else if (_count < rowCount())
    {
        int difference = rowCount() - _count;

        beginRemoveRows(QModelIndex(), _count, rowCount() - 1);

        for (int i = 0; i < difference; ++i)
        {
            m_matrix.removeLast();
        }

        endRemoveRows();
    }
}
void MatrixModel::columnCountChanged(int _count)
{
    if (_count > columnCount())
    {
        int difference = _count - columnCount();

        beginInsertColumns(QModelIndex(), columnCount(), _count - 1);

        for (int i = 0; i < rowCount(); ++i)
        {
            for (int j = 0; j < difference; ++j)
            {
               m_matrix[i].append(0);
            }
        }

        endInsertColumns();
    }
    else if (_count < columnCount())
    {
        int difference = columnCount() - _count;

        beginRemoveColumns(QModelIndex(), _count, columnCount() - 1);

        for (int i = 0; i < rowCount(); ++i)
        {
            for (int j = 0; j < difference; ++j)
            {
                 m_matrix[i].removeLast();
            }
        }

        endRemoveColumns();
    }
}
