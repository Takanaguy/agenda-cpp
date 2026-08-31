# Agenda en C++ - Version console

Petite application d'agenda en C++, avec sauvegarde et chargement des donnees
dans un fichier, gestion des evenements et interface console.

Projet reecrit de zero dans le cadre d'un cours personnel (BUT Informatique,
projet de premiere annee) pour reapprendre les bases du C++ depuis zero.

## Auteurs

- Tanguy Horard

## Fonctionnalites

- Creer un agenda vide ou charger un agenda existant depuis un fichier `.raccoon`
- Ajouter un evenement (titre, description, date de debut, date de fin)
- Supprimer un evenement par son identifiant
- Afficher tout le contenu d'un agenda
- Afficher les 10 prochains evenements a partir d'une date donnee
- Sauvegarder l'agenda dans un fichier `.raccoon`

## Structure du projet

| Fichier            | Role                                                        |
|---------------------|--------------------------------------------------------------|
| `date.hpp/.cpp`     | Structure `Date`, validation et comparaison de dates          |
| `agenda.hpp/.cpp`   | Structures `Event`/`Agenda`, creation, sauvegarde, chargement |
| `menu.hpp/.cpp`     | Menus interactifs en console (`switch`, cadre ASCII)          |
| `main.cpp`          | Point d'entree du programme                                   |

## Compilation

### Prerequis (Windows)

- [MSYS2](https://www.msys2.org/) avec le toolchain `mingw-w64-ucrt-x86_64-gcc`
- Le dossier `C:\msys64\ucrt64\bin` ajoute au PATH systeme

Verifier que tout est bien installe :

```bash
g++ --version
```

### Compiler le projet

```bash
g++ -Wall -std=c++17 -c main.cpp menu.cpp agenda.cpp date.cpp
g++ -Wall -std=c++17 -o liAgenda.exe main.o menu.o agenda.o date.o
```

Ou en une seule commande :

```bash
g++ -Wall -std=c++17 -o liAgenda.exe main.cpp menu.cpp agenda.cpp date.cpp
```

### Lancer le programme

```bash
./liAgenda.exe
```

## Format du fichier de sauvegarde (`.raccoon`)

Fichier texte simple :

```
Titre de l'agenda
Description de l'agenda
<ID de l'evenement>
<Titre de l'evenement>
<Description de l'evenement>
<jour>/<mois>/<annee>   (date de debut)
<jour>/<mois>/<annee>   (date de fin)
... (bloc de 5 lignes repete par evenement)
```

## Notes

- Le texte affiche en console n'utilise volontairement pas d'accents,
  pour eviter les problemes d'affichage lies a l'encodage du terminal Windows.
- Projet realise en autodidacte pour reapprendre le C++ (variables, structs,
  namespaces, references, vectors, fichiers, recursivite, switch/case) etape
  par etape, sans reprendre le code d'un ancien collegue.
