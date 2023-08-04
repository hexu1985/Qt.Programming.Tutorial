#include <QtWidgets/QApplication>
#include "widget.h"
#include <thread>
#include <chrono>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    MySignal s;
    QObject::connect(&s, SIGNAL(valueChanged(int)),
                     &w, SLOT(setValue(int)));

    std::thread t([&s]() { 
            for (int i = 0; i < 10; i++) {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                std::cout << i << " setValue: " << 50*i << std::endl;
                s.setValue(50*i);
             }
    });
    t.detach();

    w.resize(400, 300);
    w.setWindowTitle("Custom Signal Slot");

    w.show();

    return a.exec();
}
