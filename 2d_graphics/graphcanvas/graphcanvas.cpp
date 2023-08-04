#include <QtWidgets>

#include "graphcanvas.h"

GraphCanvas::GraphCanvas(QWidget *parent)
    : QWidget(parent)
{
}

void GraphCanvas::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    draw(&painter);
}

void GraphCanvas::draw(QPainter *painter)
{
}
