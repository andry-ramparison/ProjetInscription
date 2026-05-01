#ifndef FORMWIDGET_H
#define FORMWIDGET_H

#include <QComboBox>
#include <QLineEdit>
#include <QSpinBox>
#include <QWidget>

class FormWidget : public QWidget
{
    Q_OBJECT

public:
    explicit FormWidget(QWidget *parent = nullptr);

    QString nom() const;
    int age() const;
    QString sexe() const;
    QString niveau() const;

signals:
    void submitted();

private slots:
    void onSubmittedClicked();

private:
    QLineEdit *inputNom;
    QSpinBox *inputAge;
    QComboBox *inputSexe;
    QComboBox *inputNiveau;
};

#endif
