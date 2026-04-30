# QtInscription

QtInscription est une petite application de bureau developpee avec Qt Widgets. Elle permet de gerer une liste d'inscriptions en saisissant un nom et un age, puis en ajoutant, supprimant et copiant des elements depuis l'interface.

## Fonctionnalites

- Ajout d'une personne avec un nom et un age
- Affichage de la liste des inscrits dans une vue personnalisee
- Suppression d'un inscrit via un bouton dedie
- Copie de l'element selectionne vers le presse-papiers
- Zone laterale pour visualiser le contenu du presse-papiers
- Interface sombre avec styles Qt personnalises

## Structure du projet

- `main.cpp`: point d'entree de l'application
- `mainwindow.h` / `mainwindow.cpp`: fenetre principale et logique de l'interface
- `personne.h` / `personne.cpp`: classe simple representant une personne inscrite
- `CMakeLists.txt`: configuration de build CMake pour Qt 5 ou Qt 6

## Principe de fonctionnement

1. L'utilisateur saisit un nom et un age.
2. Le bouton `Inscrire` ajoute la personne a la liste.
3. Chaque ligne affiche le nom, l'age et un bouton de suppression.
4. Le bouton `Copier` place dans le presse-papiers le texte de l'element selectionne.
5. Le bouton `Coller` lit le contenu du presse-papiers et l'ajoute a la liste visuelle.

## Pre-requis

- CMake 3.5 ou superieur
- Qt 5 ou Qt 6 avec le module `Widgets`
- Un compilateur C++17

## Compilation

### Avec CMake

```bash
cmake -S . -B build
cmake --build build
```

### Execution

Une fois la compilation terminee, lancez l'executable genere par CMake dans le dossier `build`.

## Notes

- L'application stocke les inscriptions dans une liste interne `QList<Personne>`.
- La suppression retire a la fois l'element de l'interface et l'entree correspondante dans la liste interne.
- L'interface utilise un `QDockWidget` pour afficher le panneau clipboard.
