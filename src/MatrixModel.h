#ifndef MATRIX_MODEL_H
#define MATRIX_MODEL_H

#include <QAbstractTableModel>


class MatrixModel : public QAbstractTableModel
{
    Q_OBJECT
public:

    MatrixModel(int _rows, int _columns, QObject *_parent = 0);
    ~MatrixModel();

    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &_index, int _role = Qt::DisplayRole) const;

    bool setData(const QModelIndex &_index, const QVariant &_value, int _role = Qt::EditRole);

    Qt::ItemFlags flags(const QModelIndex &_index) const;

public slots:
    void rowCountChanged(int _count);
    void columnCountChanged(int _count);

private:

    QVector<QVector<double>> m_matrix;

};

#endif // MATRIXMODEL_H
