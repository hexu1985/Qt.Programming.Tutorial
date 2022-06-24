#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    cmmBtn = new QCommandLinkButton("Vision",
                                    "Vision Project",
                                    this);

    cmmBtn->setFlat(true);
    cmmBtn->setGeometry(0, 0, 200, 60);

    connect(cmmBtn, SIGNAL(clicked()), this, SLOT(clickFunc()));
}

void Widget::clickFunc()
{
    qDebug("QCommandLinkButton Click.");
}

Widget::~Widget()
{
}
