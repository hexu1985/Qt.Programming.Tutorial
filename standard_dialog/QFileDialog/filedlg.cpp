#include "filedlg.h"
#include <QFileDialog>
#include <QDebug>
#include <QCoreApplication>

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

    connect(btnOpen,SIGNAL(clicked()),this,SLOT(on_btnOpen_clicked()));
    connect(btnOpenMulti,SIGNAL(clicked()),this,SLOT(on_btnOpenMulti_clicked()));
    connect(btnSelDir,SIGNAL(clicked()),this,SLOT(on_btnSelDir_clicked()));
    connect(btnSave,SIGNAL(clicked()),this,SLOT(on_btnSave_clicked()));
}

void FileDlg::on_btnOpen_clicked()
{ //选择单个文件
    QString curPath=QDir::currentPath();//获取系统当前目录
//  QString  curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    QString dlgTitle="选择一个文件"; //对话框标题
    QString filter="文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)"; //文件过滤器

    QString aFileName=QFileDialog::getOpenFileName(this,dlgTitle,curPath,filter);

    if (!aFileName.isEmpty())
        qDebug() << "file: " << aFileName;
}

void FileDlg::on_btnOpenMulti_clicked()
{ //选择多个文件
//  QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    QString curPath=QDir::currentPath();//获取系统当前目录
    QString dlgTitle="选择多个文件"; //对话框标题
    QString filter="文本文件(*.txt);;图片文件(*.jpg *.gif *.png);;所有文件(*.*)"; //文件过滤器

    QStringList fileList=QFileDialog::getOpenFileNames(this,dlgTitle,curPath,filter);
    for (int i=0; i<fileList.count();i++)
        qDebug() << i << " file: " << fileList.at(i);
}

void FileDlg::on_btnSelDir_clicked()
{ //选择文件夹
    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
//  QString curPath=QDir::currentPath();//获取系统当前目录
//调用打开文件对话框打开一个文件

    QString dlgTitle="选择一个目录"; //对话框标题
    QString selectedDir=QFileDialog::getExistingDirectory(this,dlgTitle,curPath,QFileDialog::ShowDirsOnly);
    if (!selectedDir.isEmpty())
        qDebug() << "dir: " << selectedDir;
}

void FileDlg::on_btnSave_clicked()
{//保存文件
    QString curPath=QCoreApplication::applicationDirPath(); //获取应用程序的路径
    QString dlgTitle="保存文件"; //对话框标题
    QString filter="文本文件(*.txt);;h文件(*.h);;C++文件(.cpp);;所有文件(*.*)"; //文件过滤器
    QString aFileName=QFileDialog::getSaveFileName(this,dlgTitle,curPath,filter);
    if (!aFileName.isEmpty())
        qDebug() << "file: " << aFileName;
}

FileDlg::~FileDlg()
{

}
