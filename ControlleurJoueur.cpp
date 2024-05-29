#include "ControlleurJoueur.h"

ControlleurJoueur::ControlleurJoueur() : hitPoint(0), pPlateau(nullptr)
{

}

void ControlleurJoueur::setPlateau(class Plateau* plateau)
{
    // Init le ptr du plateau du joueur
    this->pPlateau = plateau;
}

class Plateau* ControlleurJoueur::getPlateau()
{
    // renvoi un pointeur sur le plateau joueur
    return this->pPlateau;
}

bool ControlleurJoueur::tir(class Plateau* plateau, unsigned int x, unsigned int y)
{
    // Si pas touché ==> on tire sur le plateau de tir, on incrémente hitPoint, on renvoi true
    if(!plateau.touche(x, y))
    {
        hitPoint++;
        this->plateau.tir(x, y);
        return true;
    }
    return false;
}

unsigned int ControlleurJoueur::getHitPoints()
{
    return this->hitPoint;
}