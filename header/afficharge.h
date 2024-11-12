#include <iostream>
#include <vector>

#ifndef AFFICHARGE_H
#define AFFICHARGE_H

int longueur(const char* chaine);
std::string MotAleatoire();
void afficherMot(const std::string &mot, const bool lettres[], int taille);
bool Victoire(const bool lettres[], int taille);
void afficherPendu(int tentatives);
void BarreDeVie(int tentatives, int tentativesMax);

#endif