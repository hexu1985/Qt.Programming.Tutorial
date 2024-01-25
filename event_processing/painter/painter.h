#pragma once

#include <QPushButton>
#include "drawwidget.h"

class QToolButton;
class QComboBox;
class QSpinBox;

class Painter : public QWidget
{
    Q_OBJECT
public:
    Painter(QWidget *parent=0);
    
public slots:
    bool eventFilter(QObject*,QEvent*);
    
private: 
    DrawWidget *canvas;
    QPushButton *clearButton;
};

