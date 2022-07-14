#include "game.h"
#include "mainview.h"

Game::Game()
    : timer(new QTimer),
      scene(new QGraphicsScene),
      view(new MainView(this)),
      timeout(300)
{
    for (int i = 0; i < rows; ++i)
    {
        cells.push_back(QVector<Cell *>());
        for (int j = 0; j < cols; ++j)
        {
            cells[i].push_back(new Cell(i, j, this, view));
            scene->addItem(cells[i][j]);
        }
    }

    //    for (int i = 0; i < rows; ++i)
    //        for (int j = 0; j < cols; ++j)
    //            count_change(i, j);

    timer->setInterval(timeout);
    connect(timer, SIGNAL(timeout()), this, SLOT(my_update()));

    //    view->setTransformationAnchor(QGraphicsView::NoAnchor);
    //    view->translate(-100, -100);
    //    view->resize(800, 400);
    view->setScene(scene);
    view->show();
}

Game::~Game()
{
    delete timer;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            delete cells[i][j];
}

void Game::my_update()
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
        {
            cells[i][j]->cell_update();
        }

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            count_change(i, j);

    view->viewport()->update();
}

void Game::count_change(int row, int col)
{
    int change = cells[row][col]->get_change();
    if (change == 0)
        return;

    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (row + i < rows && row + i >= 0 && col + j < cols && col + j >= 0 && (i != 0 || j != 0))
                cells[row + i][col + j]->add_count(change);
}

void Game::pause()
{
    if (timer->isActive())
        timer->stop();
    else
        timer->start();
}

bool Game::is_pause()
{
    return !timer->isActive();
}

void Game::change_timeout(int change)
{
    if (timeout + change > 0 && timeout + change <= maxTimeout)
        timeout += change;
    timer->setInterval(timeout);
}

void Game::clear()
{
    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            cells[i][j]->clear();
    timer->stop();
    view->viewport()->update();
}
