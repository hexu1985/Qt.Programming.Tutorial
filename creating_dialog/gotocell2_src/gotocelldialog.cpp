#include "gotocelldialog.h"

#include <QLabel>
#include <QSpacerItem>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegExpValidator>


GoToCellDialog::GoToCellDialog(QWidget *parent)
    : QDialog(parent)
{
    QLabel* label = new QLabel("&Cell Location:", this);
    lineEdit = new QLineEdit(this);
    label->setBuddy(lineEdit);
    QRegExp regExp("[A-Za-z][1-9][0-9]{0,2}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
    QHBoxLayout* hboxLayout1 = new QHBoxLayout();
    hboxLayout1->addWidget(label);
    hboxLayout1->addWidget(lineEdit);

    QSpacerItem *spacerItem = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    okButton = new QPushButton("ok", this);
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

    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
    connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged(QString)
{
    okButton->setEnabled(lineEdit->hasAcceptableInput());
}
