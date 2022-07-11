#include "mainview.h"
#include "game.h"

MainView::MainView(Game *game): game(game)
{

}

void MainView::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_P)
        game->pause();
    if (e->key() == Qt::Key_N)
        if (game->is_pause())
            game->my_update();
}
