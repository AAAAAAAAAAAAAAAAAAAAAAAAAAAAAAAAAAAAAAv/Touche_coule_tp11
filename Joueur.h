#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "Plateau.h"

class Joueur : public ControlleurJoueur
{
protected:
    std::string nomJoueur;

public:
    explicit Joueur(std::string nom = "tommy");
    ~Joueur() virtual;

};

#endif // JOUEUR_H