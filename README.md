# QtInscription

QtInscription est une application de bureau réalisée avec Qt Widgets pour gérer une liste d'inscriptions étudiantes. L'interface permet de saisir les informations d'une personne, de les afficher dans un tableau, de filtrer la liste et de conserver les données dans un fichier JSON local.

## Fonctionnalités

- Formulaire d'ajout avec nom, âge, sexe et niveau
- Tableau récapitulatif des personnes inscrites
- Suppression d'une ligne depuis le tableau
- Recherche simple sur le contenu affiché
- Sauvegarde et chargement automatiques via `inscrits.json`
- Thème visuel chargé depuis les ressources Qt

## Arborescence

```text
QtInscription/
├── CMakeLists.txt
├── include/
│   ├── mainwindow.h
│   ├── models/
│   │   ├── inscription.h
│   │   └── personne.h
│   └── widgets/
│       ├── formwidget.h
│       └── searchwidget.h
├── resources/
│   ├── resources.qrc
│   └── styles/
│       └── style.qss
└── src/
    ├── main.cpp
    ├── mainwindow.cpp
    ├── models/
    │   ├── inscription.cpp
    │   └── personne.cpp
    └── widgets/
        ├── formwidget.cpp
        └── searchwidget.cpp
```

## Organisation du code

- `src/main.cpp` initialise l'application Qt et charge la feuille de style embarquée
- `src/mainwindow.cpp` contient la fenêtre principale, le tableau et la logique d'interaction
- `src/widgets/formwidget.cpp` gère le formulaire d'inscription
- `src/widgets/searchwidget.cpp` expose le champ de recherche
- `src/models/personne.cpp` définit le modèle de données d'une personne
- `src/models/inscription.cpp` gère la liste interne, la sérialisation JSON et le chargement au démarrage
- `resources/resources.qrc` embarque les ressources Qt dans l'exécutable

## Compilation

### Prérequis

- CMake 3.5 ou supérieur
- Qt 5 ou Qt 6 avec le module `Widgets`
- Un compilateur C++17

### Génération et build

```bash
cmake -S . -B build
cmake --build build
```

### Exécution

Lancez ensuite l'exécutable généré dans le dossier `build`.

## Données locales

L'application enregistre les inscriptions dans un fichier `inscrits.json` créé dans le répertoire d'exécution. Si vous lancez le programme depuis un dossier différent, le fichier sera créé à cet endroit.

## Notes

- La feuille de style est chargée depuis `:/style.qss`
- Les données sont sauvegardées au format JSON pour rester lisibles et faciles à réutiliser
- La table affiche les inscriptions avec une action de suppression par ligne
