#include "painter.h"
#include <QVBoxLayout>
#include <QEvent>
#include <QMouseEvent>
#include <iostream>

Painter::Painter(QWidget *parent)
	: QWidget(parent)
{
    setWindowTitle("Simple Painter");    
   
    QVBoxLayout *vboxLayout = new QVBoxLayout();

    clearButton = new QPushButton("clear", this);
    vboxLayout->addWidget(clearButton);
    
    canvas = new DrawWidget;
    canvas->setWidth(2);
    canvas->setColor(Qt::black); 
    vboxLayout->addWidget(canvas);

    setLayout(vboxLayout);

    setMinimumSize(600,400);

    connect(clearButton, SIGNAL(clicked()), canvas, SLOT(clear()));
	canvas->installEventFilter(this);
}

bool Painter::eventFilter(QObject* watched,QEvent* event)
{
	if(watched == canvas)
	{
		if(event->type() == QEvent::MouseButtonPress)
		{
			QMouseEvent *mouseEvent = (QMouseEvent *)event;	
            QPoint startPos = mouseEvent->pos();
            std::cout << __func__ << ", e->pos(): (" << startPos.x() << ", " << startPos.y() << ")" << std::endl;
		}		
		if(event->type() == QEvent::MouseButtonRelease)
		{
			QMouseEvent *mouseEvent = (QMouseEvent *)event;	
		}	
	}

	return QWidget::eventFilter(watched,event);	
}
