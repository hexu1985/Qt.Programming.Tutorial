#include <QGridLayout>
#include <QLabel>
#include <QSpacerItem>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QStringList>

#include "sortdialog.h"

SortDialog::SortDialog(QWidget *parent)
    : QDialog(parent)
{
    QGridLayout* mainLayout = new QGridLayout(this);

    // buttons
    QVBoxLayout* vboxLayout = new QVBoxLayout();
    QPushButton* okButton = new QPushButton("OK", this);
    vboxLayout->addWidget(okButton);
    QPushButton* cancelButton = new QPushButton("Cancle", this);
    vboxLayout->addWidget(cancelButton);
    QSpacerItem* spacerItem = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    vboxLayout->addItem(spacerItem);
    QPushButton* moreButton = new QPushButton("More", this);
    moreButton->setCheckable(true);
    vboxLayout->addWidget(moreButton);
    mainLayout->addLayout(vboxLayout, 0, 1, 2, 1);

    // primaryGroupBox
    QGroupBox* primaryGroupBox = new QGroupBox("&Primary Key", this);
    QGridLayout* gridLayout1 = new QGridLayout(primaryGroupBox);
    QLabel* primaryColumnLabel = new QLabel("Column:", primaryGroupBox);
    gridLayout1->addWidget(primaryColumnLabel, 0, 0, 1, 1);
    primaryColumnCombo = new QComboBox(primaryGroupBox);
    gridLayout1->addWidget(primaryColumnCombo, 0, 1, 1, 1);
    QSpacerItem* spacerItem1 = new QSpacerItem(31, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);
    gridLayout1->addItem(spacerItem1, 0, 2, 1, 1);
    QLabel* primaryOrderLabel = new QLabel("Order:", primaryGroupBox);
    gridLayout1->addWidget(primaryOrderLabel, 1, 0, 1, 1);
    primaryOrderCombo = new QComboBox(primaryGroupBox);
    gridLayout1->addWidget(primaryOrderCombo, 1, 1, 1, 2);
    mainLayout->addWidget(primaryGroupBox, 0, 0, 1, 1);

    // spacerItem
    QSpacerItem* spacerItem4 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    mainLayout->addItem(spacerItem4, 1, 0, 1, 1);

    // secondaryGroupBox 
    QGroupBox* secondaryGroupBox = new QGroupBox("&Secondary", this);
    QGridLayout* gridLayout2 = new QGridLayout(secondaryGroupBox);
    QLabel* secondaryColumnLabel = new QLabel("Column:", secondaryGroupBox);
    gridLayout2->addWidget(secondaryColumnLabel, 0, 0, 1, 1);
    secondaryColumnCombo = new QComboBox(secondaryGroupBox);
    gridLayout2->addWidget(secondaryColumnCombo, 0, 1, 1, 1);
    QSpacerItem* spacerItem2 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout2->addItem(spacerItem2, 0, 2, 1, 1);
    QLabel* secondaryOrderLabel = new QLabel("Order:", secondaryGroupBox);
    gridLayout2->addWidget(secondaryOrderLabel, 1, 0, 1, 1);
    secondaryOrderCombo = new QComboBox(secondaryGroupBox);
    gridLayout2->addWidget(secondaryOrderCombo, 1, 1, 1, 2);
    mainLayout->addWidget(secondaryGroupBox, 2, 0, 1, 1);

    // tertiaryGroupBox
    QGroupBox* tertiaryGroupBox = new QGroupBox("&Secondary", this);
    QGridLayout* gridLayout3 = new QGridLayout(tertiaryGroupBox);
    QLabel* tertiaryColumnLabel = new QLabel("Column:", tertiaryGroupBox);
    gridLayout3->addWidget(tertiaryColumnLabel, 0, 0, 1, 1);
    tertiaryColumnCombo = new QComboBox(tertiaryGroupBox);
    gridLayout3->addWidget(tertiaryColumnCombo, 0, 1, 1, 1);
    QSpacerItem* spacerItem3 = new QSpacerItem(20, 0, QSizePolicy::Minimum, QSizePolicy::Expanding);
    gridLayout3->addItem(spacerItem3, 0, 2, 1, 1);
    QLabel* tertiaryOrderLabel = new QLabel("Order:", tertiaryGroupBox);
    gridLayout3->addWidget(tertiaryOrderLabel, 1, 0, 1, 1);
    tertiaryOrderCombo = new QComboBox(tertiaryGroupBox);
    gridLayout3->addWidget(tertiaryOrderCombo, 1, 1, 1, 2);
    mainLayout->addWidget(tertiaryGroupBox, 3, 0, 1, 1);

    setLayout(mainLayout);

    // signals and slots
    QObject::connect(moreButton, SIGNAL(toggled(bool)), secondaryGroupBox, SLOT(setVisible(bool)));
    QObject::connect(moreButton, SIGNAL(toggled(bool)), tertiaryGroupBox, SLOT(setVisible(bool)));
    QObject::connect(okButton, SIGNAL(clicked()), this, SLOT(accept()));
    QObject::connect(cancelButton, SIGNAL(clicked()), this, SLOT(reject()));

    okButton->setDefault(true);

    secondaryGroupBox->hide();
    tertiaryGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    setOrderOption();
    setColumnRange('A', 'Z');
}

void SortDialog::setOrderOption()
{
    QStringList list;
    list << "Ascending" << "Descending";
    primaryOrderCombo->clear();
    primaryOrderCombo->insertItems(0, list);
    secondaryOrderCombo->clear();
    secondaryOrderCombo->insertItems(0, list);
    tertiaryOrderCombo->clear();
    tertiaryOrderCombo->insertItems(0, list);
}

void SortDialog::setColumnRange(QChar first, QChar last)
{
    primaryColumnCombo->clear();
    secondaryColumnCombo->clear();
    tertiaryColumnCombo->clear();

    secondaryColumnCombo->addItem(tr("None"));
    tertiaryColumnCombo->addItem(tr("None"));

    primaryColumnCombo->setMinimumSize(
            secondaryColumnCombo->sizeHint());

    QChar ch = first;
    while (ch <= last) {
        primaryColumnCombo->addItem(QString(ch));
        secondaryColumnCombo->addItem(QString(ch));
        tertiaryColumnCombo->addItem(QString(ch));
        ch = ch.unicode() + 1;
    }
}
