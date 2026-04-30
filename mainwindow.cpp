#include <QApplication>
#include <QClipboard>
#include <QDockWidget>
#include <QLabel>
#include <QMenuBar>
#include <QPushButton>
#include <QVBoxLayout>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Inscription App");
    resize(700, 500);

    // ======== SIDEBAR ===========
    QDockWidget *dock = new QDockWidget("Clipboard", this);

    QWidget *side = new QWidget;
    QVBoxLayout *sideLayout = new QVBoxLayout;

    QPushButton *btnCopy = new QPushButton("Copier");
    QPushButton *btnPaste = new QPushButton("Coller");

    clipboardView = new QTextEdit;
    clipboardView->setPlaceholderText("Clipboard...");

    sideLayout->addWidget(clipboardView);
    sideLayout->addWidget(btnCopy);
    sideLayout->addWidget(btnPaste);

    side->setLayout(sideLayout);
    dock->setWidget(side);

    dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
    dock->setFeatures(QDockWidget::DockWidgetClosable | QDockWidget::DockWidgetMovable);

    menuBar()->addAction(dock->toggleViewAction());

    addDockWidget(Qt::LeftDockWidgetArea, dock);

    // ====== CENTRE (form + list) ============
    QWidget *central = new QWidget;
    QVBoxLayout *mainLayout = new QVBoxLayout;

    // FORM
    QHBoxLayout *form = new QHBoxLayout;

    inputNom = new QLineEdit;
    inputNom->setPlaceholderText("Nom");

    inputAge = new QSpinBox;
    inputAge->setRange(0, 120);

    QPushButton *btnAdd = new QPushButton("Inscrire");

    form->addWidget(inputNom);
    form->addWidget(inputAge);
    form->addWidget(btnAdd);

    // LISTE
    list = new QListWidget;
    list->setSelectionMode(QAbstractItemView::SingleSelection);
    list->setFocusPolicy(Qt::StrongFocus);

    mainLayout->addLayout(form);
    mainLayout->addWidget(list);

    central->setLayout(mainLayout);
    setCentralWidget(central);

    // ======= SIGNALS =======
    connect(btnAdd, &QPushButton::clicked, this, &MainWindow::inscrire);
    connect(btnCopy, &QPushButton::clicked, this, &MainWindow::copier);
    connect(btnPaste, &QPushButton::clicked, this, &MainWindow::coller);

    // ======== STYLE ======
    setStyleSheet(R"(

    QMainWindow {
        background-color: #1e1e2f;
    }

    QLineEdit, QSpinBox, QTextEdit {
        background-color: #2c2c3e;
        color: white;
        border: 1px solid #444;
        border-radius: 6px;
        padding: 6px;
    }

    QPushButton {
        background-color: #3a7afe;
        color: white;
        border-radius: 6px;
        padding: 6px 10px;
    }

    QPushButton:hover {
        background-color: #5a92ff;
    }

    QListWidget {
        background-color: #2c2c3e;
        color: white;
        border: none;
    }

    QDockWidget {
        color: white;
    }

    QDockWidget::title {
        background: #2c2c3e;
        padding: 5px;
    }
    )");
}


MainWindow::~MainWindow() {}

// ======= INSCRIPTION ======
void MainWindow::inscrire()
{
    QString nom = inputNom->text();
    int age = inputAge->value();

    if (nom.isEmpty()) return;

    Personne p(nom, age);
    inscrits.append(p);

    ajouterItemUI(p);

    inputNom->clear();
}

// AJOUT VISUEL
void MainWindow::ajouterItemUI(const Personne &p)
{
    QListWidgetItem *item = new QListWidgetItem(list);

    QWidget *rowWidget = new QWidget;
    QHBoxLayout *layout = new QHBoxLayout;

    QLabel *label = new QLabel(p.nom + " (" + QString::number(p.age) + ")");

    QPushButton *btnDelete = new QPushButton("❌");
    btnDelete->setFixedWidth(40);

    btnDelete->setStyleSheet(R"(
        QPushButton {
            background-color: #ff4d4d;
            color: white;
            border-radius: 6px;
        }
        QPushButton:hover {
            background-color: #ff6666;
        }
    )");

    layout->addWidget(label);
    layout->addStretch();
    layout->addWidget(btnDelete);

    layout->setSpacing(10);
    layout->setContentsMargins(10, 8, 10, 8);

    rowWidget->setLayout(layout);

    list->addItem(item);
    list->setItemWidget(item, rowWidget);

    rowWidget->setMinimumHeight(50);
    item->setSizeHint(QSize(0, 50));

    rowWidget->setCursor(Qt::PointingHandCursor);
    rowWidget->installEventFilter(this);

    // connexion bouton supprimer
    connect(btnDelete, &QPushButton::clicked, [=]() {
        supprimerItem(rowWidget);
    });
}

// ====== SUPPRESSION =====
void MainWindow::supprimerItem(QWidget *itemWidget)
{
    for (int i = 0; i < list->count(); i++)
    {
        QListWidgetItem *item = list->item(i);

        if (list->itemWidget(item) == itemWidget)
        {
            inscrits.removeAt(i);
            delete list->takeItem(i);
            return;
        }
    }
}

//======= CLIPBOARD ======
void MainWindow::copier()
{
    QListWidgetItem *item = list->currentItem();
    if (!item) return;

    QWidget *widget = list->itemWidget(item);

    QLabel *label = widget->findChild<QLabel*>();
    if (!label) return;

    QString text = label->text();

    QApplication::clipboard()->setText(text);
    clipboardView->setText(text);
}

void MainWindow::coller()
{
    QString text = QApplication::clipboard()->text();
    if (text.isEmpty()) return;

    QListWidgetItem *item = new QListWidgetItem;

    QWidget *widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(widget);

    QLabel *label = new QLabel(text);
    layout->addWidget(label);

    item->setSizeHint(widget->sizeHint());
    list->setItemWidget(item, widget);
}
