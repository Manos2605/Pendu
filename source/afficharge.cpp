#include "../header/afficharge.h"
#include <cstdlib>
#include <ctime>

int longueur(const char* chaine){
    int length = 0;
    while (chaine[length]!= '\0') {
        length++;
    }
    
    return length;
}

std::string MotAleatoire() {
    std::string mots[] = {"PROGRAMMATION", "JEUX", "VIDEO", "ELDEN", "CONSOLE", "CODE", "C++", "DARKSOUL", "BLOODBORNE"};
    int nombreDeMots = sizeof(mots) / sizeof(mots[0]);

    srand(time(0));
    int indexAleatoire = rand() % nombreDeMots;
    
    return mots[indexAleatoire];
}

void afficherMot(const std::string &mot, const bool lettres[], int taille) {
    for (int i = 0; i < taille; ++i) {
        if (lettres[i])
            std::cout << mot[i] << " ";
        else
            std::cout << "_ ";
    }
    std::cout << std::endl;
}

bool Victoire(const bool lettres[], int taille) {
    for (int i = 0; i < taille; ++i) {
        if (!lettres[i]) return false;
    }
    return true;    
}

void afficherPendu(int tentatives) {
    if (tentatives == 6) {
        std::cout << "   +---+\n   |   |\n       |\n       |\n       |\n       |\n=========\n";
    } else if (tentatives == 5) {
        std::cout << "   +---+\n   |   |\n   O   |\n       |\n       |\n       |\n=========\n";
    } else if (tentatives == 4) {
        std::cout << "   +---+\n   |   |\n   O   |\n   |   |\n       |\n       |\n=========\n";
    } else if (tentatives == 3) {
        std::cout << "   +---+\n   |   |\n   O   |\n  /|   |\n       |\n       |\n=========\n";
    } else if (tentatives == 2) {
        std::cout << "   +---+\n   |   |\n   O   |\n  /|\\  |\n       |\n       |\n=========\n";
    } else if (tentatives == 1) {
        std::cout << "   +---+\n   |   |\n   O   |\n  /|\\  |\n  /    |\n       |\n=========\n";
    } else if (tentatives == 0) {
        std::cout << "   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n       |\n=========\n";
    } else {
        std::cout << "   +---+\n   |   |\n   O   |\n  /|\\  |\n  / \\  |\n   |   |\n=========\n";
    }
}

void BarreDeVie(int tentatives, int tentativesMax) {
    int longueurBarre = 10; // Taille de la barre de vie (10 caractères par exemple)
    int remplissage = (tentatives * longueurBarre) / tentativesMax;
    
    std::cout << "\n(Point de vie) PV : [";
    for (int i = 0; i < longueurBarre; ++i) {
        if (i < remplissage)
            std::cout << "█"; // Vie restante
        else
            std::cout << "-"; // Vie perdue
    }
    std::cout << "]" << std::endl;
}