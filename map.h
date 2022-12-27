#ifndef MAP_H
#define MAP_H

#include <QObject>

#include "mapobject.h"

class Map : public QObject
{
    Q_OBJECT
public:
    Map();

    void addObject(mapObject* newObject);

private:
    static const int length = 2000;
    static const int width = 2000;

    // все элемнты на карте
    QVector <mapObject*> objects;
};

#endif // MAP_H
