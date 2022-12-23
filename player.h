#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsScene>

#include <Windows.h>

#include <QTimer>

class Player : public QObject, public QGraphicsItem
{
    Q_OBJECT
signals:

public slots:
    void move(int x, int y); // Слот, который отвечает за обработку перемещения Игрока

public:
    explicit Player(QObject *parent = nullptr);

protected:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

private slots:
    void tactSpin(); // повернуть на один тик
    void tactRun();

private:
    void spin(double angleA, double angleB);
    QTimer* timerSpin;
    bool vector;

    qreal angle;    // Угол поворота графического объекта
    double newAngle;

    double speedRun;   // Скорость передвижения игрока
    QTimer* timerRun;

    double speedSpin;  // Скорость поворота игрока

    int newX;
    int newY;
};

#endif // PLAYER_H
