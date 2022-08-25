
QT       += core gui

TARGET = FileDialog
TEMPLATE = app

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


SOURCES += main.cpp\
        filedlg.cpp

HEADERS  += filedlg.h
