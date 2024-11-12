#include <iostream>
#include "header/afficharge.h"


int main() {
    bool partie = true; 
    int score = 0;
    while(partie){
        std::string mot = MotAleatoire();
        int tailleMot = longueur(mot.c_str());
        bool lettresTrouvees[tailleMot] = {false};
        int tentativesRestantes = 6;
        // Utilisation d'une barre de vie pour afficher le nombre de tentatives restantes.
        //int tentativesMax = tentativesRestantes;
        char lettre;

        std::cout << "Bienvenue sur le jeu vidéo du Pendu" << std::endl;

        while (tentativesRestantes > 0 && !Victoire(lettresTrouvees, tailleMot)) {
            std::cout << "\nMot à découvrir : ";
            afficherMot(mot, lettresTrouvees, tailleMot);
            afficherPendu(tentativesRestantes);
            //BarreDeVie(tentativesRestantes, tentativesMax)
            std::cout << "Point de vie (PV) : " << tentativesRestantes << std::endl;
            std::cout << "Proposez une lettre : ";
            std::cin >> lettre;

            bool lettreTrouvee = false;
            for (int i = 0; i < tailleMot; ++i) {
                if (toupper(lettre) == mot[i]) {
                    lettresTrouvees[i] = true;
                    lettreTrouvee = true;
                }
            }

            if (!lettreTrouvee) {
                tentativesRestantes--;
                std::cout << "Lettre incorrecte !" << std::endl;
            }

            // Nettoyage de la console.
            #ifdef _WIN32
                system("CLS");
            #else
                system("clear");
            #endif
        }

        if (Victoire(lettresTrouvees, tailleMot)) {
            std::cout << "\nWIN ! Mot trouvé : " << mot << std::endl;
            score++;
        } else {
            afficherPendu(tentativesRestantes);
            std::cout << "\nGAME OVER. Le mot était : " << mot << std::endl;
        }

        std::cout << "\nScore actuel : " << score << std::endl;

        std::cout << "\nVoulez vous rejouer(o/n) : ";
        char rejouer;
        std::cin >> rejouer;
        if (rejouer!= 'o' && rejouer != 'O') {
            partie = false;
        }

    }

    return 0;
}