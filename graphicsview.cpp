#include "graphicsview.h"

#include <QDebug>

graphicsView::graphicsView(QWidget *parent, QGraphicsScene* scene) : QGraphicsView(parent)
{
    setScene(scene);

    setRenderHint(QPainter::Antialiasing);    /// Устанавливаем сглаживание
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по вертикали
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff); /// Отключаем скроллбар по горизонтали

    scene->setSceneRect(-300,-300, 600,600); /// Устанавливаем область графической сцены

    /* Дополнительно нарисуем органичение территории в графической сцене */
    scene->addLine(-300,-300, 300,-300, QPen(Qt::black));
    scene->addLine(-300, 300, 300, 300, QPen(Qt::black));
    scene->addLine(-300,-300,-300, 300, QPen(Qt::black));
    scene->addLine( 300,-300, 300, 300, QPen(Qt::black));

    //    scene->addLine(-250,0,250,0,QPen(Qt::black));   /// Добавляем горизонтальную линию через центр
    //    scene->addLine(0,-250,0,250,QPen(Qt::black));   /// Добавляем вертикальную линию через центр
}

void graphicsView::mousePressEvent(QMouseEvent *mouseEvent)
{
    //qDebug() << QString::number(mouseEvent->x() + 300) << QString::number(mouseEvent->y() + 300);

    emit movePlayer(mouseEvent->x() - 300, mouseEvent->y() - 300);
}
