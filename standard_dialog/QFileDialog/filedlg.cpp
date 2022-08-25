#include "filedlg.h"
#include <QFileDialog>

FileDlg::FileDlg(QWidget *parent) :
    QDialog(parent)
{
    setWindowTitle(tr("标准文件对话框的实例"));

    mainLayout = new QGridLayout();

    btnOpen = new QPushButton(tr("打开一个文件"));
    btnOpenMulti = new QPushButton(tr("打开多个文件"));
    btnSelDir = new QPushButton(tr("选择已有目录"));
    btnSave = new QPushButton(tr("保存文件"));

    mainLayout->addWidget(btnOpen, 0, 0);
    mainLayout->addWidget(btnOpenMulti, 0, 1);
    mainLayout->addWidget(btnSelDir, 1, 0);
    mainLayout->addWidget(btnSave, 1, 1);

    setLayout(mainLayout);
}

FileDlg::~FileDlg()
{

}
