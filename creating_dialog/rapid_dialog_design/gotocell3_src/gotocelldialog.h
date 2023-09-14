#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QDialogButtonBox>

class GoToCellDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit* lineEdit;
    QDialogButtonBox* buttonBox;

public:
    GoToCellDialog(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged(QString);
};

#endif
