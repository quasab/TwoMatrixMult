#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include "MatrixModel.h"
#include "MultMatrixThread.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

//! Класс главного окна.
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    //! Конструктор класса.
    /*! \param _parent - родительский виджет.
     */
    MainWindow(QWidget *_parent = nullptr);
    //! Дейструктор.
    ~MainWindow();

private slots:

    //! Обрабатывает нажатие на кнопку "Умножить".
    void multSlot();
    //! Обрабатывает нажатие на кнопку "Сброс".
    void resetSlot();

private:

    //! Компоненты графического интерфейса.
    Ui::MainWindow *m_ui;

    //! Левая матрица.
    MatrixModel *m_leftMatrix;
    //! Правая матрица.
    MatrixModel *m_rightMatrix;
    //! Матрица с результатом.
    MatrixModel *m_resultMatrix;
    //! Список потоков.
    QList<MultMatrixThread*> m_threads;
};
#endif // MAIN_WINDOW_H
