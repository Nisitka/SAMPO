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

public:
    explicit graphicsView(QWidget* parent, QGraphicsScene* scene);

protected:
    virtual void mousePressEvent(QMouseEvent* mouseEvent);
};

#endif // GRAPHICSVIEW_H
