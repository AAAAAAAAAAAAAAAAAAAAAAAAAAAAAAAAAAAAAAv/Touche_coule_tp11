#include "IA.h"

IA::IA()
{
    // initialise la partie ControlleurJoueur
    ControlleurJoueur();

}

void IA::ajouterBateau(class Bateau* bateau, unsigned int x, unsigned int y)
{
    this->pPlateau->ajoutBateau(bateau, x, y);
}