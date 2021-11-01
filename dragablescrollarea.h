#ifndef DRAGABLESCROLLAREA_H
#define DRAGABLESCROLLAREA_H

#include <QScrollArea>
#include <QPoint>

class DragableScrollArea : public QScrollArea
{
    Q_OBJECT
public:
    DragableScrollArea(QWidget *parent = nullptr);
    ~DragableScrollArea();

private:
    QPoint *prevPos;
    // QWidget interface
protected:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};

#endif // DRAGABLESCROLLAREA_H
