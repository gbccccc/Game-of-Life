#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "cell.h"

class MainWindow : public QObject
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

    void count_change(int row, int col);
    bool is_pause();

    void pause();

public slots:
    void my_update();
private:
    QTimer *timer;

    QGraphicsScene *scene;
    QGraphicsView *view;

    const int rows = 50, cols = 50;
    QVector<QVector<Cell *>> cells;
};
#endif // MAINWINDOW_H
