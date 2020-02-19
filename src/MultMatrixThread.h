#ifndef MULTMATRIXTHREAD_H
#define MULTMATRIXTHREAD_H

#include "MatrixModel.h"
#include <QThread>

class MultMatrixThread : public QThread
{
public:
    MultMatrixThread(const MatrixModel *_leftMatrix,
                     const MatrixModel *_rightMatrix,
                     MatrixModel *_resultMatrix,
                     int _begin,
                     int _end);
    ~MultMatrixThread();

    void run();
private:

    const MatrixModel *m_leftMatrix;
    const MatrixModel *m_rightMatrix;
    MatrixModel *m_resultMatrix;
    int m_begin;
    int m_end;
};

#endif // MULTMATRIXTHREAD_H
