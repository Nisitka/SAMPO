#ifndef MAPOBJECT_H
#define MAPOBJECT_H

#include <QGraphicsItem>

// элемент, находящийся на карте
class mapObject
{
public:
    mapObject(QGraphicsItem* item, int x, int y);

    void move(int newX, int newY);

private:
    // координаты на карте
    int x;
    int y;

    // графическое представление этого объекта
    QGraphicsItem* item;
};

#endif // MAPOBJECT_H
