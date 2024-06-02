#include "Joueur.h"

Joueur::Joueur(std::string nom) : ControlleurJoueur(), nomJoueur(nom)
{
    // on lui crée son propre plateau
    this->pPlateau = new Plateau;
}

Joueur::~Joueur()
{
    delete pPlateau;
}