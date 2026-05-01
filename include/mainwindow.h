#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>

#include "widgets/formwidget.h"
#include "widgets/searchwidget.h"
#include "models/inscription.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void refreshList();

private:
    FormWidget *form;
    SearchWidget *search;

    QTableWidget *table;

    Inscription inscrits;
};

#endif // MAINWINDOW_H
