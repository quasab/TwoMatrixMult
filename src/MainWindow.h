#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "MatrixModel.h"
#include "MultMatrixThread.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    void multSlot();
    void resetSlot();

private:
    Ui::MainWindow *m_ui;

    MatrixModel *m_leftMatrix;
    MatrixModel *m_rightMatrix;
    MatrixModel *m_resultMatrix;

    QList<MultMatrixThread*> m_threads;
};
#endif // MAINWINDOW_H
