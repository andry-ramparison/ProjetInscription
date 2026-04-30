#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QLineEdit>
#include <QList>
#include <QListWidget>
#include <QMainWindow>
#include <QSpinBox>
#include <QTextEdit>

#include "personne.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void inscrire();
    void supprimerItem(QWidget *itemWidget);
    void copier();
    void coller();

private:
    QList<Personne> inscrits;

    // UI elements
    QLineEdit *inputNom;
    QSpinBox *inputAge;
    QListWidget *list;

    QTextEdit *clipboardView;

    void ajouterItemUI(const Personne &p);

};

#endif
