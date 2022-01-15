#include "clipboardwidget.h"
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QApplication>
#include <QClipboard>

ClipboardWidget::ClipboardWidget(QWidget *parent)
    : QWidget(parent)
{
    sourceEdit = new QLineEdit;
    targetEdit = new QLineEdit;
    QLabel *sourceLabel = new QLabel("source :");
    QLabel *targetLabel = new QLabel("target :");

    sourceLabel->setBuddy(sourceEdit);
    targetLabel->setBuddy(targetEdit);

    QPushButton *sourceButton = new QPushButton;
    sourceButton->setText("copy");
    QPushButton *targetButton = new QPushButton;
    targetButton->setText("paste");

    QHBoxLayout *layout1 = new QHBoxLayout;
    layout1->addWidget(sourceLabel);
    layout1->addWidget(sourceEdit);

    QHBoxLayout *layout2 = new QHBoxLayout;
    layout2->addWidget(targetLabel);
    layout2->addWidget(targetEdit);

    QHBoxLayout *layout3 = new QHBoxLayout;
    layout3->addWidget(sourceButton);
    layout3->addWidget(targetButton);

    QVBoxLayout *mainlayout = new QVBoxLayout;
    mainlayout->addLayout(layout1);
    mainlayout->addLayout(layout2);
    mainlayout->addLayout(layout3);
    mainlayout->addStretch();

    setLayout(mainlayout);

    connect(sourceButton, SIGNAL(clicked()), this, SLOT(setClipboard()));
    connect(targetButton, SIGNAL(clicked()), this, SLOT(getClipboard()));
}

ClipboardWidget::~ClipboardWidget()
{
}

void ClipboardWidget::setClipboard()
{
    QClipboard *clipboard = QApplication::clipboard();
    clipboard->setText(sourceEdit->text());
}

void ClipboardWidget::getClipboard()
{
    QClipboard *clipboard = QApplication::clipboard();
    targetEdit->setText(clipboard->text());
}
