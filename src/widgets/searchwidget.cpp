#include <QVBoxLayout>

#include "widgets/searchwidget.h"

SearchWidget::SearchWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout;

    search = new QLineEdit;
    search->setPlaceholderText("Rechercher...");

    layout->addWidget(search);
    setLayout(layout);
}

QLineEdit *SearchWidget::line() const
{
    return search;
}
