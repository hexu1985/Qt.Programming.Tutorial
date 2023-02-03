#pragma once

#include <QDialog>
#include <QGridLayout>
#include <QPushButton>
#include <QLineEdit>

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
    QLineEdit *pathLineEdit;

private slots:
    void on_btnOpen_clicked();

    void on_btnOpenMulti_clicked();

    void on_btnSelDir_clicked();

    void on_btnSave_clicked();
};


