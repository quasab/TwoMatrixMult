#ifndef MULT_MATRIX_THREAD_H
#define MULT_MATRIX_THREAD_H

#include "MatrixModel.h"

#include <QThread>

//! Класс управляющий потоком.
class MultMatrixThread : public QThread
{

public:

    //! Конструктор класса.
    /*! \param _leftMatrix - левая матрица.
     *  \param _rightMatrix - правая матрица.
     *  \param _resultMatrix - матрица с результатом.
     *  \param _begin - номер строки матрицы с которой поток начнет работу.
     *  \param _end - номер строки матрицы перед которой поток закончит работу.
     */
    MultMatrixThread(const MatrixModel *_leftMatrix,
                     const MatrixModel *_rightMatrix,
                     MatrixModel *_resultMatrix,
                     int _begin,
                     int _end);
    //! Деструктор класса.
    ~MultMatrixThread();

    //! Выполняет код в потоке.
    void run();

private:

    //! Левая матрица.
    const MatrixModel *m_leftMatrix;
    //! Правая матрица.
    const MatrixModel *m_rightMatrix;
    //! Матрица с результатом.
    MatrixModel *m_resultMatrix;
    //! Номер строки матрицы с которой поток начнет работу.
    int m_begin;
    //! Номер строки матрицы перед которой поток закончит работу.
    int m_end;
};

#endif // MULT_MATRIX_THREAD_H
