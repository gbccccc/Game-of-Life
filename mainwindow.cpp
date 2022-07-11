#include "mainwindow.h"
#include "mainview.h"

MainWindow::MainWindow()
    : timer(new QTimer),
      scene(new QGraphicsScene),
      view(new MainView(this))
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

    connect(timer, SIGNAL(timeout()), this, SLOT(my_update()));

    view->setTransformationAnchor(QGraphicsView::NoAnchor);
    //    view->translate(-100, -100);
    view->resize(800, 400);
    view->setScene(scene);
    view->show();
}

MainWindow::~MainWindow()
{
    delete timer;

    for (int i = 0; i < rows; ++i)
        for (int j = 0; j < cols; ++j)
            delete cells[i][j];
}

void MainWindow::my_update()
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

void MainWindow::count_change(int row, int col)
{
    int change = cells[row][col]->get_change();
    if (change == 0)
        return;

    for (int i = -1; i <= 1; ++i)
        for (int j = -1; j <= 1; ++j)
            if (row + i < rows && row + i >= 0 && col + j < cols && col + j >= 0 && (i != 0 || j != 0))
                cells[row + i][col + j]->add_count(change);
}

void MainWindow::pause()
{
    if (timer->isActive())
        timer->stop();
    else
        timer->start(200);
}

bool MainWindow::is_pause()
{
    return !timer->isActive();
}
