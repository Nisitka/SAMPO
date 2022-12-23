#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>

#include "player.h"

#include "graphicsview.h"

namespace Ui {
class window;
}

class window : public QWidget
{
    Q_OBJECT
signals:

public:
    explicit window(QWidget *parent = nullptr);
    ~window();



private:
    graphicsView*    graphicsArea;
    QGraphicsScene*  scene;         // Объявляем графическую сцену
    Player*          player1;

    Ui::window *ui;
};

#endif // WINDOW_H
