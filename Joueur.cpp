#include "Joueur.h"

Joueur::Joueur(std::string nom) : nomJoueur(nom)
{
    this->ControlleurJoueur();
    // on lui crée son propre plateau
    this->pPlateau = new Plateau;
}

~Joueur::Joueur()
{
    delete pPlateau;
}