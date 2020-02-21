#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "MatrixModel.h"

MainWindow::MainWindow(QWidget *parent):
    QMainWindow(parent),
    m_ui(new Ui::MainWindow),
    m_leftMatrix(NULL),
    m_rightMatrix(NULL),
    m_resultMatrix(NULL)
{
    m_ui->setupUi(this);

    connect(m_ui->sbLeftColumns, SIGNAL(valueChanged(int)),
            m_ui->sbRightRows, SLOT(setValue(int)));

    connect(m_ui->sbRightRows, SIGNAL(valueChanged(int)),
            m_ui->sbLeftColumns, SLOT(setValue(int)));

    connect(m_ui->pbMult, SIGNAL(clicked(bool)),
            this, SLOT(multSlot()));
    connect(m_ui->pbReset, SIGNAL(clicked(bool)),
            this, SLOT(resetSlot()));

    resetSlot();
}

MainWindow::~MainWindow()
{
    delete m_ui;
    m_ui = NULL;

    delete m_leftMatrix;
    m_leftMatrix = NULL;

    delete m_rightMatrix;
    m_rightMatrix = NULL;

    delete m_resultMatrix;
    m_resultMatrix = NULL;

    qDeleteAll(m_threads);
    m_threads.clear();
}

void MainWindow::multSlot()
{
    qDeleteAll(m_threads);
    m_threads.clear();

    if (m_resultMatrix != NULL)
    {
        delete m_resultMatrix;
        m_resultMatrix = NULL;
    }

    m_resultMatrix = new MatrixModel(m_ui->sbLeftRows->value(),
                                     m_ui->sbRightColumns->value(),
                                     this);

    m_ui->tvResultMatrix->setModel(m_resultMatrix);

    int threadCount = QThread::idealThreadCount();

    if (threadCount > m_resultMatrix->rowCount())
    {
        threadCount = m_resultMatrix->rowCount();
    }

    int addings = m_resultMatrix->rowCount() % threadCount;
    int step = m_resultMatrix->rowCount() / threadCount;
    int begin = 0;
    int end = 0;

    for (int i = 0; i < threadCount; ++i)
    {
        begin = end;
        end += step;

        if (addings > 0)
        {
            end++;
            addings--;
        }

        m_threads.append(new MultMatrixThread(m_leftMatrix,
                                              m_rightMatrix,
                                              m_resultMatrix,
                                              begin,
                                              end));
    }

    for (int i = 0; i < m_threads.count();++i)
    {
        m_threads.at(i)->start();
    }
}

void MainWindow::resetSlot()
{
    if (m_resultMatrix != NULL)
    {
        delete m_resultMatrix;
        m_resultMatrix = NULL;
    }

    if (m_leftMatrix != NULL)
    {
        delete m_leftMatrix;
        m_leftMatrix = NULL;
    }

    if (m_rightMatrix != NULL)
    {
        delete m_rightMatrix;
        m_rightMatrix = NULL;
    }

    m_leftMatrix = new MatrixModel(1, 1, this);
    m_ui->sbLeftRows->setValue(1);
    m_ui->sbLeftColumns->setValue(1);
    m_ui->tvLeftMatrix->setModel(m_leftMatrix);

    m_rightMatrix = new MatrixModel(1, 1, this);
    m_ui->sbRightRows->setValue(1);
    m_ui->sbRightColumns->setValue(1);
    m_ui->tvRightMatrix->setModel(m_rightMatrix);

    connect(m_ui->sbLeftRows, SIGNAL(valueChanged(int)),
            m_leftMatrix, SLOT(rowCountChanged(int)));
    connect(m_ui->sbRightRows, SIGNAL(valueChanged(int)),
            m_rightMatrix, SLOT(rowCountChanged(int)));

    connect(m_ui->sbLeftColumns, SIGNAL(valueChanged(int)),
            m_leftMatrix, SLOT(columnCountChanged(int)));
    connect(m_ui->sbRightColumns, SIGNAL(valueChanged(int)),
            m_rightMatrix, SLOT(columnCountChanged(int)));

    qDeleteAll(m_threads);
    m_threads.clear();
}
