#include "mainwindow.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //    QGraphicsScene *scene = new QGraphicsScene;  //场景
    //    Cell *item = new Cell(0, 0); //矩形项
    //    Cell *item2 = new Cell(20, 20); //矩形项
    //    scene->addItem(item);  //项添加到场景
    //    scene->addItem(item2);  //项添加到场景
    //    QGraphicsView *view = new QGraphicsView; //视图
    //    view->setScene(scene);  //视图关联场景
    //    view->show();  */ 显示视图
    MainWindow w;
    return a.exec();
}
