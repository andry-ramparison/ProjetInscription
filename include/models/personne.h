#ifndef PERSONNE_H
#define PERSONNE_H

#include <QJsonObject>
#include <QString>

class Personne
{
public:
    Personne();

    QString getNom() const;
    void setNom(const QString &value);

    int getAge() const;
    void setAge(int value);

    QString getSexe() const;
    void setSexe(const QString &value);

    QString getNiveau() const;
    void setNiveau(const QString &value);

    QJsonObject toJson() const;
    static Personne fromJson(const QJsonObject &obj);

private:
    QString nom;
    int age;
    QString sexe;
    QString niveau;
};

#endif
