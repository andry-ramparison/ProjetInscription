#include <QLabel>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QTableWidget>
#include <QHeaderView>
#include <QLineEdit>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Inscription App");
    resize(800, 600);

    QWidget *central = new QWidget;
    QVBoxLayout *main = new QVBoxLayout;

    QHBoxLayout *top = new QHBoxLayout;

    form = new FormWidget;
    search = new SearchWidget;

    table = new QTableWidget;

    // TABLE CONFIG
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels(
        {"Nom", "Âge", "Sexe", "Niveau", "Action"}
        );

    table->setEditTriggers(QAbstractItemView::NoEditTriggers);
    table->setSelectionBehavior(QAbstractItemView::SelectRows);
    table->setSelectionMode(QAbstractItemView::SingleSelection);
    table->horizontalHeader()->setStretchLastSection(true);

    top->addWidget(form);
    top->addWidget(search);

    main->addLayout(top);
    main->addWidget(table);

    central->setLayout(main);
    setCentralWidget(central);

    // LOAD AU DÉMARRAGE
    inscrits.load();
    refreshList();

    // =========================
    // AJOUT INSCRIPTION
    // =========================
    connect(form, &FormWidget::submitted, this, [=]() {

        if (form->nom().trimmed().isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Nom obligatoire !");
            return;
        }

        Personne p;
        p.setNom(form->nom());
        p.setAge(form->age());
        p.setSexe(form->sexe());
        p.setNiveau(form->niveau());

        inscrits.add(p);
        inscrits.save();
        refreshList();
    });

    // =========================
    // SEARCH (filtrage simple)
    // =========================
    connect(search->line(), &QLineEdit::textChanged,
            this, [=](const QString &text) {

                for (int i = 0; i < table->rowCount(); i++)
                {
                    bool match = false;

                    for (int j = 0; j < 4; j++)
                    {
                        auto item = table->item(i, j);
                        if (item && item->text().toLower().contains(text.toLower())) {
                            match = true;
                        }
                    }

                    table->setRowHidden(i, !match);
                }
            });
}

MainWindow::~MainWindow() {}


// =========================
// REFRESH TABLE
// =========================
void MainWindow::refreshList()
{
    table->setRowCount(0);

    const auto data = inscrits.getAll();

    for (int row = 0; row < data.size(); row++)
    {
        const Personne &p = data[row];

        table->insertRow(row);

        table->setItem(row, 0, new QTableWidgetItem(p.getNom()));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(p.getAge())));
        table->setItem(row, 2, new QTableWidgetItem(p.getSexe()));
        table->setItem(row, 3, new QTableWidgetItem(p.getNiveau()));

        QPushButton *del = new QPushButton("❌");
        table->setCellWidget(row, 4, del);

        connect(del, &QPushButton::clicked, this, [=]() {
            inscrits.remove(row);
            inscrits.save();
            refreshList();
        });
    }
}
