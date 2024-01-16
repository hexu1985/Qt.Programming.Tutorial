#include <QtGui>
#include "drawwidget.h"

DrawWidget::DrawWidget()	
{
    setAutoFillBackground(true);
	
    QPalette palette = this->palette();
    palette.setColor(QPalette::Window,Qt::white);
    setPalette(palette);
    
    pix = new QPixmap(size());
    pix->fill(Qt::white);
    
    setMinimumSize(600,400);
}

DrawWidget::~DrawWidget()	
{
    delete pix;
}

void DrawWidget::setStyle(int s)
{
    style = s;
}

void DrawWidget::setWidth(int w)
{
    weight = w;
}

void DrawWidget::setColor(QColor c)
{
    color = c;
}

void DrawWidget::mousePressEvent(QMouseEvent * e)
{
    startPos = e->pos();
}

void DrawWidget::mouseMoveEvent(QMouseEvent * e)
{
    QPainter painter;
    QPen pen;
    pen.setStyle((Qt::PenStyle)style);      	
    pen.setWidth(weight);
    pen.setColor(color);
    painter.begin(pix);
    painter.setPen(pen);
    
    painter.drawLine(startPos,e->pos());
    painter.end();
    startPos = e->pos();
    update();
    
}

void DrawWidget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(QPoint(0,0),*pix);
}


void DrawWidget::resizeEvent(QResizeEvent * event)
{
    if(height() > pix->height() || width() > pix->width())
    {
        QPixmap *newPix = new QPixmap(size());
        newPix->fill(Qt::white);
        QPainter p(newPix);
        p.drawPixmap(QPoint(0,0),*pix);
        delete pix;
        pix = newPix;
    }
    QWidget::resizeEvent(event);
}


void DrawWidget::clear()
{
    QPixmap *clearPix = new QPixmap(size());
    clearPix->fill(Qt::white);
    delete pix;
    pix = clearPix;
    update();
}
