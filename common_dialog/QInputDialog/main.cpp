#include "inputdlg.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    InputDlg w;
    w.show();
    
    return a.exec();
}
