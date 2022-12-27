#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>

#include <QGraphicsScene>
#include <QShortcut>
#include <QTimer>

#include "graphicsview.h"

#include "player.h"

namespace Ui {
class window;
}

class window : public QWidget
{
    Q_OBJECT
signals:

public slots:
    void updateInfoPlayer();

public:
    explicit window(QWidget *parent = nullptr);
    ~window();

    void setPlayer(Player* player);

private:
    graphicsView*    graphicsArea;
    QGraphicsScene*  scene;         // Объявляем графическую сцену

    // настройка визуала полосок жизни и маны
    void setStyleBars();

    // персонаж, которым мы будем управлять
    Player* player;

    QTimer* updateTimer;

    Ui::window *ui;
};

#endif // WINDOW_H
