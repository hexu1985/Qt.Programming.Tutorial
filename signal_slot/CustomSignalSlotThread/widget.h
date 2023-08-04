#ifndef WIDGET_H
#define WIDGET_H

#include <QtWidgets/QLabel>

class MySignal : public QObject
{
    Q_OBJECT

public:
    MySignal() { m_value = 0; }

    int value() const { return m_value; }

    void setValue(int value);

signals:
    void valueChanged(int newValue);

private:
    int m_value;
};


class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = 0);
    ~Widget();

public slots:
    void setValue(int value);

private:
    QLabel *lbl;

};

#endif // WIDGET_H
