#include <QApplication>
#include <QDebug>
#include <QFile>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QFile file(":/style.qss");

    if (!file.open(QFile::ReadOnly))
    {
        qDebug() << "QSS NOT FOUND";
    }
    else
    {
        qApp->setStyleSheet(file.readAll());
    }

    MainWindow w;
    w.show();
    return a.exec();
}
