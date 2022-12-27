#include "graphicsview.h"

#include <QDebug>

graphicsView::graphicsView(QWidget *parent, QGraphicsScene* scene_) : QGraphicsView(parent)
{
    scene = scene_;
    setScene(scene);

    this->setFixedSize(width, length);

    setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали

    scene->setSceneRect(-width/2,-length/2, width,length); /// Устанавливаем область графической сцены
    //scene->setSceneRect();

    /* Дополнительно нарисуем органичение территории в графической сцене */
//    scene->addLine(-300,-300, 300,-300, QPen(Qt::black));
//    scene->addLine(-300, 300, 300, 300, QPen(Qt::black));
//    scene->addLine(-300,-300,-300, 300, QPen(Qt::black));
//    scene->addLine( 300,-300, 300, 300, QPen(Qt::black));

}

// пользователь нажал на клавишу мыши в области графической сцены:
void graphicsView::mousePressEvent(QMouseEvent *mouseEvent)
{
    //qDebug() << QString::number(mouseEvent->x() + 300) << QString::number(mouseEvent->y() + 300);

    // идти, если правая кнопка мыши
    if (mouseEvent->buttons() == Qt::RightButton)
    {
        emit movePlayer(mouseEvent->x() - width/2, mouseEvent->y() - length/2);
    }

}
