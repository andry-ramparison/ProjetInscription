#include "models/personne.h"

Personne::Personne() {}

QString Personne::getNom() const
{
    return nom;
}

void Personne::setNom(const QString &value)
{
    nom = value;
}

int Personne::getAge() const
{
    return age;
}

void Personne::setAge(int value)
{
    age = value;
}

QString Personne::getSexe() const
{
    return sexe;
}

void Personne::setSexe(const QString &value)
{
    sexe = value;
}

QString Personne::getNiveau() const
{
    return niveau;
}

void Personne::setNiveau(const QString &value)
{
    niveau = value;
}

QJsonObject Personne::toJson() const
{
    return {
        {"nom", nom},
        {"age", age},
        {"sexe", sexe},
        {"niveau", niveau}
    };
}

Personne Personne::fromJson(const QJsonObject &obj)
{
    Personne p;
    p.setNom(obj["nom"].toString());
    p.setAge(obj["age"].toInt());
    p.setSexe(obj["sexe"].toString());
    p.setNiveau(obj["niveau"].toString());

    return p;
}
