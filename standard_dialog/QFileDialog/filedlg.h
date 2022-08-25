#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>

class FileDlg : public QDialog
{
    Q_OBJECT

public:
    FileDlg(QWidget *parent = 0);
    ~FileDlg();

    QPushButton *btnOpen;
    QPushButton *btnOpenMulti;
    QPushButton *btnSelDir;
    QPushButton *btnSave;
    QGridLayout *mainLayout;
};


