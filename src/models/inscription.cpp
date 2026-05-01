#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>

#include "models/inscription.h"

void Inscription::add(const Personne &p)
{
    data.append(p);
}

void Inscription::remove(int index)
{
    if (index >= 0 && index < data.size())
    {
        data.removeAt(index);
    }
}

QVector<Personne> Inscription::getAll() const
{
    return data;
}

void Inscription::save()
{
    QJsonArray arr;
    for (const Personne &p : data)
    {
        arr.append(p.toJson());
    }

    QFile file("inscrits.json");
    file.open(QIODevice::WriteOnly);
    file.write(QJsonDocument(arr).toJson());
}

void Inscription::load()
{
    QFile file("inscrits.json");
    if (!file.open(QIODevice::ReadOnly)) return;

    QJsonArray arr = QJsonDocument::fromJson(file.readAll()).array();

    data.clear();
    for(auto v : arr)
    {
        data.append(Personne::fromJson(v.toObject()));
    }
}
