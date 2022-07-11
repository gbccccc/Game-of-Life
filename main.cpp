#include "game.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Game game;
    return a.exec();
}
