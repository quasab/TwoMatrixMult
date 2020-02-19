#include "MultMatrixThread.h"

MultMatrixThread::MultMatrixThread(const MatrixModel *_leftMatrix,
                                   const MatrixModel *_rightMatrix,
                                   MatrixModel *_resultMatrix,
                                   int _begin,
                                   int _end):
    m_leftMatrix(_leftMatrix),
    m_rightMatrix(_rightMatrix),
    m_resultMatrix(_resultMatrix),
    m_begin(_begin),
    m_end(_end)
{
}

MultMatrixThread::~MultMatrixThread()
{

}

void MultMatrixThread::run()
{
    for (int i = m_begin; i < m_end; ++i)
    {
        for (int j = 0; j < m_rightMatrix->columnCount(); ++j)
        {
            double matrixIJ = 0;

            for (int k = 0; k < m_leftMatrix->columnCount(); ++k)
            {
                QModelIndex indexLeft = m_leftMatrix->index(i, k);
                QModelIndex indexRight = m_rightMatrix->index(k, j);
                matrixIJ += m_leftMatrix->data(indexLeft).toDouble() *
                            m_rightMatrix->data(indexRight).toDouble();
            }
            QModelIndex resultIndex = m_resultMatrix->index(i, j);
            m_resultMatrix->setData(resultIndex, matrixIJ);
        }
    }
}
