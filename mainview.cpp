#include "mainview.h"
#include "mainwindow.h"

MainView::MainView(MainWindow *mw): mw(mw)
{

}

void MainView::keyPressEvent(QKeyEvent *e)
{
    if (e->key() == Qt::Key_P)
        mw->pause();
    if (e->key() == Qt::Key_N)
        if (mw->is_pause())
            mw->my_update();
}
