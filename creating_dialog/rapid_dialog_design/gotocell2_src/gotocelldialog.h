#ifndef GOTOCELLDIALOG_H
#define GOTOCELLDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QPushButton>

class GoToCellDialog : public QDialog
{
    Q_OBJECT

private:
    QLineEdit* lineEdit;
    QPushButton* okButton;

public:
    GoToCellDialog(QWidget *parent = 0);

private slots:
    void on_lineEdit_textChanged(QString);
};

#endif
