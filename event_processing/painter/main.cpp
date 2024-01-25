#include <QApplication>
#include "painter.h"

int
main(int argc, char * argv[])
{
    QApplication app(argc,argv);
    Painter p;
    p.show();
    return app.exec();
}
