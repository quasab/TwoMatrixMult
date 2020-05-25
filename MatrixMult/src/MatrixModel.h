#ifndef MATRIX_MODEL_H
#define MATRIX_MODEL_H

#include <QAbstractTableModel>

//! Класс описывающий модель матрицы.
class MatrixModel : public QAbstractTableModel
{
    Q_OBJECT

public:

    //! Конструктор класса.
    /*! \param _rows - количество строк.
     *  \param _columns - количествостолбцов.
     *  \param _parent - указатель на родительский объект.
     */
    MatrixModel(int _rows, int _columns, QObject *_parent = 0);
    //! Деструктор класса.
    ~MatrixModel();

    //! Возвращает количество строк матрицы.
    /*! \param _parent - не используется.
     *  \return - количество строк матрицы.
     */
    int rowCount(const QModelIndex &_parent = QModelIndex()) const;
    //! Возвращает количество столбцов матрицы.
    /*! \param _parent - не используется.
     *  \return - количество столбцов матрицы.
     */
    int columnCount(const QModelIndex &_parent = QModelIndex()) const;
    //! Возвращает значение элемента матрицы по индексу.
    /*! \param _index - индекс элемента.
     *  \param _role - роль элемента.
     *  \return - значение элемента.
     */
    QVariant data(const QModelIndex &_index, int _role = Qt::DisplayRole) const;
    //! Устанавливает значение элемента матрицы по индексу.
    /*! \param _index - индекс элемента в матрице.
     *  \param _value - значение элемента.
     *  \param _role - роль элемента.
     *  \return - успешность установки значения.
     */
    bool setData(const QModelIndex &_index,
                 const QVariant &_value,
                 int _role = Qt::EditRole);
    //! Возвращает набор флагов для элемента по индексу.
    /*! \param _index - индекс элемента.
     *  \return - набор флагов.
     */
    Qt::ItemFlags flags(const QModelIndex &_index) const;

public slots:

    //! Обрабатывает изменение числа строк в матрице.
    /*! \param _count - число строк.
     */
    void rowCountChanged(int _count);
    //! Обрабатывает изменение числа столбцов в матрице.
    /*! \param _count - число столбцов.
     */
    void columnCountChanged(int _count);

private:

    //! Матрица.
    QVector<QVector<double>> m_matrix;

};

#endif // MATRIX_MODEL_H
