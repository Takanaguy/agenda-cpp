#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include "menu.hpp"

void clearScreen() {
    system("cls");
}
// efface le contenu du terminal (commande Windows), pour que chaque menu
// s'affiche "propre" sans les anciens menus au-dessus

void printMenuFrame(const std::vector<std::string> &lines) {
    size_t maxLen = 0;
    for (const std::string &l : lines) {
        if (l.size() > maxLen)
            maxLen = l.size();
    }

    std::string border = "+" + std::string(maxLen + 2, '-') + "+";

    std::cout << border << std::endl;
    for (const std::string &l : lines) {
        std::cout << "| " << l << std::string(maxLen - l.size(), ' ') << " |" << std::endl;
    }
    std::cout << border << std::endl;
}
// dessine un cadre ASCII autour d'une liste de lignes de texte
// calcule d'abord la longueur de la plus longue ligne pour que le cadre soit bien aligne

void menu::launch(agenda::Agenda &agenda) {
    unsigned int userChoice = 0;
    do {
        clearScreen();
        std::vector<std::string> lines = {
            "Bienvenue sur la version console de l'Agenda !",
            "",
            "Voulez-vous :",
            "1. Creer un agenda vide",
            "2. Ouvrir un fichier agenda existant"
        };
        printMenuFrame(lines);
        std::cout << "Que faire ? > ";

        std::cin >> userChoice;
        std::string dummy;
        std::getline(std::cin, dummy);

        switch (userChoice) {
            case 1:
                agenda = agenda::createEmptyAgenda();
                options(agenda);
                break;
            case 2:
                agenda = agenda::loadAgenda();
                options(agenda);
                break;
            default:
                std::cout << "Choix invalide. Veuillez reessayer." << std::endl;
                break;
        }

    } while (userChoice != 1 && userChoice != 2);
}

bool readYesNo() {
    char c;
    std::cout << "[Y/N] > ";
    do {
        std::cin >> c;
        std::string dummy;
        std::getline(std::cin, dummy);
        if (c == 'Y' || c == 'y')
            return true;
        if (c == 'N' || c == 'n')
            return false;
    } while (c != 'Y' && c != 'y' && c != 'N' && c != 'n');
    return false;
}

void menu::options(agenda::Agenda &agenda) {
    unsigned int userChoice = 0;
    do {
        clearScreen();
        std::vector<std::string> lines = {
            "Agenda ouvert.",
            "Voulez-vous :",
            "3. Sauvegarder l'agenda",
            "4. Afficher le contenu de l'agenda",
            "5. Afficher les 10 prochains evenements",
            "6. Ajouter un evenement",
            "7. Supprimer un evenement",
            "8. Quitter l'application"
        };
        printMenuFrame(lines);
        std::cout << "Que faire ? > ";

        std::cin >> userChoice;
        std::string dummy;
        std::getline(std::cin, dummy);

        switch(userChoice) {
            case 3:
                agenda::saveAgenda(agenda);
                break;
            case 4:
                agenda::printAgenda(agenda);
                break;
            case 5:
                agenda::printNextTenEvents(agenda);
                break;
            case 6:
                agenda::addEvent(agenda);
                break;
            case 7:
                agenda::delEvent(agenda);
                break;
            case 8:
                if (agenda::isSaved)
                    break;
                std::cout << "Vous n'avez pas sauvegarde l'agenda." << std::endl
                           << "Souhaitez-vous enregistrer vos changements avant de quitter ?" << std::endl;
                if (readYesNo()) {
                    agenda::saveAgenda(agenda);
                    break;
                }
            default:
                std::cout << "Choisissez une des options proposees." << std::endl;
                break;
        }

        if (userChoice != 8) {
            std::cout << std::endl << "Appuyez sur Entree pour continuer...";
            std::cin.get();
        }
    } while(userChoice > 0 && userChoice < 8);
}
