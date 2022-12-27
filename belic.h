#ifndef BELIC_H
#define BELIC_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

#include "player.h"

class Belic : public Player
{

public slots:
    void Q();
    void W();
    void E();
    void R();

public:
    Belic(QObject *parent = nullptr);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

};

#endif // BELIC_H
