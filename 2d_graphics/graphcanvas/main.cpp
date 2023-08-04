#include <QApplication>

#include "graphcanvas.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    GraphCanvas graphCanvas;
    graphCanvas.setWindowTitle(QObject::tr("Graph Canvas"));
    graphCanvas.resize(300, 300);
    graphCanvas.show();
    return app.exec();
}
