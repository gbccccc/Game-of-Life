#ifndef CELL_H
#define CELL_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>

#include "mainview.h"

class Game;

class Cell : public QObject, public QGraphicsItem
{
    Q_OBJECT

public:
    Cell(int row, int col, Game *mw, QGraphicsView *view);
    void live();
    void die();
    void add_count(int count);
    bool is_alive();
    int get_change();

    void cell_update();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    const int length = 15;

private:

    bool alive;
    int surroundCount;
    int row;
    int col;
    int change;

    Game *game;
    QGraphicsView *view;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
};

#endif // CELL_H
