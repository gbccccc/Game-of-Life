#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>

class Game;

class MainView : public QGraphicsView
{
public:
    MainView(Game *mw);

    void update_paint();
private:
    Game *game;
protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // MAINVIEW_H
