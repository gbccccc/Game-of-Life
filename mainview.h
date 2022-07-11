#ifndef MAINVIEW_H
#define MAINVIEW_H

#include <QGraphicsView>
#include <QKeyEvent>

class MainWindow;

class MainView : public QGraphicsView
{
public:
    MainView(MainWindow *mw);

    void update_paint();
private:
    MainWindow *mw;
protected:
    void keyPressEvent(QKeyEvent *e);
};

#endif // MAINVIEW_H
