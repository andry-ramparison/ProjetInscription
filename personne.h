#ifndef PERSONNE_H
#define PERSONNE_H

#include <QString>

class Personne
{
public:
    QString nom;
    int age;

    Personne(QString n = "", int a = 0);
};

#endif
