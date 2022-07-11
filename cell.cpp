#include "cell.h"
#include "game.h"
#include "mainview.h"

Cell::Cell(int row, int col, Game *game, QGraphicsView *view)
    : alive(false),
      surroundCount(0),
      row(row), col(col),
      change(0),
      game(game),
      view(view)
{
    this->setPos(col * length, row * length);
}

void Cell::clear()
{
    this->change = 0;
    this->alive = false;
    this->surroundCount = 0;
}

void Cell::add_count(int count)
{
    surroundCount += count;
}

bool Cell::is_alive()
{
    return alive;
}

int Cell::get_change()
{
    return change;
}

QRectF Cell::boundingRect() const
{
    qreal penWidth = 1;
    return QRectF(0 - penWidth / 2, 0 - penWidth / 2,
                  length + penWidth / 2, length + penWidth / 2);
}

void Cell::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    if (alive)
        painter->setBrush(Qt::red);
    else
        painter->setBrush(Qt::transparent);
    painter->drawRect(0, 0, length, length);
}

void Cell::cell_update()
{
    if ((surroundCount < 2 || surroundCount > 3) && alive)
    {
        alive = false;
        change = -1;
    }
    else if (surroundCount == 3 && !alive)
    {
        alive = true;
        change = 1;
    }
    else
        change = 0;
}

void Cell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() != Qt::LeftButton)
    {
        event->ignore();
        return;
    }

    if (!game->is_pause())
    {
        event->ignore();
        return;
    }

    alive = !alive;
    if (alive)
        change = 1;
    else
        change = -1;

    game->count_change(row, col);
    view->viewport()->update();
}
