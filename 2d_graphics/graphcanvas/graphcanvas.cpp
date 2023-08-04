#include <QtWidgets>

#include "graphcanvas.h"

GraphCanvas::GraphCanvas(QWidget *parent)
    : QWidget(parent)
{
}

void GraphCanvas::paintEvent(QPaintEvent * /* event */)
{
    QPainter painter(this);

    int side = qMin(width(), height())*9/10;

    painter.setViewport((width() - side) / 2, (height() - side) / 2,
                        side, side);
    painter.setWindow(-50, -50, 100, 100);

    draw(&painter);
}

void GraphCanvas::draw(QPainter *painter)
{
    int W = 100;
    int H = 100;
    painter->drawPie(-50, -50, W, H, 0*16, 360*16);
    QBrush brush(Qt::red, Qt::SolidPattern);
    painter->setBrush(brush);
    painter->drawPie(-50, -50, W, H, 0*16, 90*16);
}
