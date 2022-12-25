#include "player.h"

#include <QDebug>

#include <cmath>

Player::Player(QObject *parent) : QObject(parent)
{
    angle = -45;
    speedRun = 3;
    speedSpin = 1.4;
    setRotation(angle); // Устанавилваем угол поворота графического объекта

    timerSpin = new QTimer;
    connect(
            timerSpin, SIGNAL(timeout()),
            this,      SLOT(tactSpin())
            );

    timerRun = new QTimer;
    connect(
            timerRun, SIGNAL(timeout()),
            this,     SLOT(tactRun())
            );
}

QRectF Player::boundingRect() const
{
    return QRectF(-25,-40,50,80);   /// Ограничиваем область, в которой лежит треугольник
}

void Player::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
        QPolygon polygon;   /// Используем класс полигона, чтобы отрисовать треугольник
        /// Помещаем координаты точек в полигональную модель
        polygon << QPoint(0,-40) << QPoint(25,40) << QPoint(-25,40);
        painter->setBrush(Qt::red);     /// Устанавливаем кисть, которой будем отрисовывать объект
        painter->drawPolygon(polygon);  /// Рисуем треугольник по полигональной модели
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

void Player::spin(double a, double b)
{
    vector = a - b < 0;


    timerSpin->start(10);
}

void Player::tactSpin()
{
    if (vector)
    {
        angle += speedSpin;
    }
    else
    {
        angle -= speedSpin;
    }

    setRotation(angle);
    if (abs(angle - newAngle) < speedSpin)
    {
        timerSpin->stop();

        timerRun->start(20);
    }
}

void Player::tactRun()
{
    setPos(mapToParent(0, -speedRun));

    if (abs(this->x() - newX) < 2*speedRun && abs(this->y() - newY) < 2*speedRun)
    {
        timerRun->stop();
    }
}

void Player::move(int x, int y)
{
    timerRun->stop();
    timerSpin->stop();

    newX = x;
    newY = y;

    double dX, dY;

    dX = newX - this->x();
    dY = newY - this->y();

    if (dY > 0)
    {
        newAngle = 180 - atan((double)dX/dY) * 57.3;
    }
    else
    {
        newAngle = -atan((double)dX/dY) * 57.3;
    }

    if (angle < -180) angle += 360;
    if (angle >  180) angle -= 360;

    qDebug() << angle << " " << newAngle;

    if (abs(newAngle - angle) > 180)
    {
        newAngle = (360 - newAngle) * (-1);
    }

    if (newAngle < -360) newAngle += 360;
    if (newAngle >  360) newAngle -= 360;

    qDebug() << angle << " " << newAngle;
    qDebug() << "__________________";


    //
    spin(angle, newAngle);

    //setRotation(newAngle);

    //setPos(x, y);

    //setPos(mapToParent(0, speed));
}

