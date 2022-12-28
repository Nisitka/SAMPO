#include "belic.h"

Belic::Belic(QObject *parent) : Player(parent)
{
    QStringList list = {"qBelic", "wBelic", "eBelic", "rBelic"};
    setPixAbilites(list);

    setPixFace("Belic");
}

QRectF Belic::boundingRect() const
{
    return QRectF(-20, -13, 40, 26);   /// Ограничиваем область, в которой лежит игрок
}

void Belic::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(QBrush(Qt::blue));
    painter->drawEllipse(-20, -13, 40, 26);

    painter->setBrush(QBrush(Qt::black));
    painter->drawRect(-13, -13, 26, 26);

    painter->setBrush(QBrush(Qt::blue));
    painter->drawEllipse(-5, -13, 10, 7);

    switch (condition)
    {
    case moving:

        break;
    case attacking:

        break;
    }

    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void Belic::Q()
{

}
void Belic::W()
{

}
void Belic::E()
{

}
void Belic::R()
{

}
