#pragma once

#include <QWidget>

class GraphCanvas : public QWidget
{
    Q_OBJECT

public:
    GraphCanvas(QWidget *parent = 0);

    void draw(QPainter *painter);

protected:
    void paintEvent(QPaintEvent *event);
};

