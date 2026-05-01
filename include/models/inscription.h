#ifndef INSCRIPTION_H
#define INSCRIPTION_H

#include <QVector>

#include "models/personne.h"

class Inscription
{
public:
    void add(const Personne &p);
    void remove(int index);

    QVector<Personne> getAll() const;

    void load();
    void save();

private:
    QVector<Personne> data;
};

#endif
