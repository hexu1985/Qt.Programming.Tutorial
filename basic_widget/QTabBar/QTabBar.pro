
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = QTabBar
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

RESOURCES += \
    resources.qrc
