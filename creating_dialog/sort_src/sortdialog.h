#ifndef SORTDIALOG_H
#define SORTDIALOG_H

#include <QDialog>
#include <QComboBox>

class SortDialog : public QDialog
{
    Q_OBJECT

private:
    QComboBox* primaryColumnCombo; 
    QComboBox* primaryOrderCombo; 
    QComboBox* secondaryColumnCombo; 
    QComboBox* secondaryOrderCombo; 
    QComboBox* tertiaryColumnCombo; 
    QComboBox* tertiaryOrderCombo; 

public:
    SortDialog(QWidget *parent = 0);

    void setOrderOption();
    void setColumnRange(QChar first, QChar last);
};

#endif
