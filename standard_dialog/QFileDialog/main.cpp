#include <QApplication>
#include "filedlg.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FileDlg w;
    w.show();

    return a.exec();
}
