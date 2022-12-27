#include "player.h"

#include <QDebug>

#include <cmath>

#include <QApplication>

Player::Player(QObject *parent) : QObject(parent)
{
    condition = moving;

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

    regainTimer = new QTimer;
    connect(
            regainTimer, SIGNAL(timeout()),
            this,        SLOT(regain())
            );
    regainTimer->start(100);
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
        angle = newAngle;

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

void Player::getMana(int &value, int &max)
{
    value = mana;
    max = maxMana;
}
void Player::getHP(int &value, int &max)
{
    value = HP;
    max = maxHP;
}

void Player::move(int x, int y)
{
    condition = moving;

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

    //
    spin(angle, newAngle);

    //setRotation(newAngle);

    //setPos(x, y);

    //setPos(mapToParent(0, speed));
}

void Player::regain()
{
    if (HP < maxHP) HP += regainHP;
    else HP = maxHP;

    if (mana < maxMana) mana += regainMana;
    else mana = maxMana;
}

