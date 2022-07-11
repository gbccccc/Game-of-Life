#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

#include "cell.h"

class Game : public QObject
{
    Q_OBJECT

public:
    Game();
    ~Game();

    void count_change(int row, int col);
    bool is_pause();

    void pause();
    void change_timeout(int change);
    void clear();
public slots:
    void my_update();
private:
    QTimer *timer;

    QGraphicsScene *scene;
    QGraphicsView *view;

    const int rows = 50, cols = 50;
    QVector<QVector<Cell *>> cells;

    const int maxTimeout = 1000;
    int timeout;
};
#endif // MAINWINDOW_H
