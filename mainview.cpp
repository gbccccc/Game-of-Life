#include "mainview.h"
#include "game.h"

MainView::MainView(Game *game): game(game)
{

}

void MainView::keyPressEvent(QKeyEvent *e)
{
    switch (e->key())
    {
    case (Qt::Key_P):
        game->pause();
        break;
    case (Qt::Key_N):
        if (game->is_pause())
            game->my_update();
        break;
    case (Qt::Key_C):
        game->clear();
        break;
    case (Qt::Key_Equal):
        game->change_timeout(-50);
        break;
    case (Qt::Key_Minus):
        game->change_timeout(50);
        break;

    }
}
