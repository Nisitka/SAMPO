#include "mapobject.h"

mapObject::mapObject(QGraphicsItem* item_, int x_, int y_)
{
    item = item_;

    x = x_;
    y = y_;
}

// переместить объект
void mapObject::move(int newX, int newY)
{
    x = newX;
    y = newY;
}
