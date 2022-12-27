#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QObject>

#include <QGraphicsView>
#include <QGraphicsScene>

#include <QMouseEvent>

class graphicsView : public QGraphicsView
{
    Q_OBJECT
signals:
    // передвижение игрока
    void movePlayer(int x, int y); // координаты куда двигаться

    // атака игрока
    void attackPlayer(int x, int y); // область, в которую хочет атаковать

public:
    explicit graphicsView(QWidget* parent, QGraphicsScene* scene);

protected:
    virtual void mousePressEvent(QMouseEvent* mouseEvent);

private:
    static const int length = 700;
    static const int width = 1000;

    QGraphicsScene* scene;
};

#endif // GRAPHICSVIEW_H
