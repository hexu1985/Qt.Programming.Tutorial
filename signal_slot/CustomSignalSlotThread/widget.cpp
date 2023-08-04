#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    lbl = new QLabel("", this);
    lbl->setGeometry(10, 10, 100, 40);

    lbl->setText(QString("%1").arg(50));
}

Widget::~Widget()
{

}

void Widget::setValue(int value)
{
    lbl->setText(QString("%1").arg(value));
}

void MySignal::setValue(int value)
{
    m_value = value;
    emit valueChanged(m_value);
}
