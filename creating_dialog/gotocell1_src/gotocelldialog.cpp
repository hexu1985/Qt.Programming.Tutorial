#include "gotocelldialog.h"

#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>
#include <QLineEdit>
#include <QHBoxLayout>
#include <QVBoxLayout>


GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel* label = new QLabel("&Cell Location:", this);
    QLineEdit *lineEdit = new QLineEdit(this);
    label->setBuddy(lineEdit);
    QHBoxLayout* hboxLayout1 = new QHBoxLayout();
    hboxLayout1->addWidget(label);
    hboxLayout1->addWidget(lineEdit);

    QSpacerItem *spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    QPushButton *okButton = new QPushButton("ok", this);
    QPushButton *cancelButton = new QPushButton("cancel", this);
    QHBoxLayout* hboxLayout2 = new QHBoxLayout();
    hboxLayout2->addItem(spacerItem);
    hboxLayout2->addWidget(okButton);
    hboxLayout2->addWidget(cancelButton);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(hboxLayout1);
    mainLayout->addLayout(hboxLayout2);

    setLayout(mainLayout);

    okButton->setEnabled(false);
}

