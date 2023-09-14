#include "gotocelldialog.h"

#include <QLabel>
#include <QPushButton>
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
    QHBoxLayout* hboxLayout = new QHBoxLayout();
    hboxLayout->addWidget(label);
    hboxLayout->addWidget(lineEdit);

    buttonBox = new QDialogButtonBox(this);
    buttonBox->setOrientation(Qt::Horizontal);
    buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::NoButton|QDialogButtonBox::Ok);

    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(hboxLayout);
    mainLayout->addWidget(buttonBox);

    setLayout(mainLayout);

    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    connect(lineEdit, SIGNAL(textChanged(QString)), this, SLOT(on_lineEdit_textChanged(QString)));
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void GoToCellDialog::on_lineEdit_textChanged(QString)
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(
            lineEdit->hasAcceptableInput());
}
