#include "dragablescrollarea.h"
#include <QMouseEvent>
#include <QScrollBar>
#include <QDebug>

DragableScrollArea::DragableScrollArea(QWidget *parent) : QScrollArea(parent), prevPos(nullptr)
{
    prevPos = new QPoint();
}

DragableScrollArea::~DragableScrollArea()
{
    delete prevPos;
}

void DragableScrollArea::mouseMoveEvent(QMouseEvent *event)
{
     int previousValueX = this->horizontalScrollBar()->value();
     int previousValueY = this->verticalScrollBar()->value();
     int offsetX = event->x() - this->prevPos->x();
     int offsetY = event->y() - this->prevPos->y();
     this->horizontalScrollBar()->setValue(previousValueX - offsetX);
     this->verticalScrollBar()->setValue(previousValueY - offsetY);
     prevPos->setX(event->x());
     prevPos->setY(event->y());
}

void DragableScrollArea::mousePressEvent(QMouseEvent *event)
{
    setCursor(Qt::OpenHandCursor);
    prevPos->setX(event->x());
    prevPos->setY(event->y());
}

void DragableScrollArea::mouseReleaseEvent(QMouseEvent *event)
{
    setCursor(Qt::ArrowCursor);
}
