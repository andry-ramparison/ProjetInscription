#include <QPushButton>
#include <QVBoxLayout>

#include "widgets/formwidget.h"

FormWidget::FormWidget(QWidget *parent)
    : QWidget{parent}
{
    QVBoxLayout *layout = new QVBoxLayout;

    inputNom = new QLineEdit;
    inputNom->setPlaceholderText("Nom");

    inputAge = new QSpinBox;
    inputAge->setRange(0, 120);

    inputSexe = new QComboBox;
    inputSexe->addItems({"Masculin", "Feminin"});

    inputNiveau = new QComboBox;
    inputNiveau->addItems({"L1", "L2", "L3", "M1", "M2"});

    QPushButton *btn = new QPushButton("Inscrire");

    layout->addWidget(inputNom);
    layout->addWidget(inputAge);
    layout->addWidget(inputSexe);
    layout->addWidget(inputNiveau);
    layout->addWidget(btn);

    setLayout(layout);

    connect(btn, &QPushButton::clicked, this, &FormWidget::onSubmittedClicked);
}

QString FormWidget::nom() const
{
    return inputNom->text();
}

int FormWidget::age() const
{
    return inputAge->value();
}

QString FormWidget::sexe() const
{
    return inputSexe->currentText();
}

QString FormWidget::niveau() const
{
    return inputNiveau->currentText();
}

void FormWidget::onSubmittedClicked()
{
    emit submitted();
}
