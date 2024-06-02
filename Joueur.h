#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>
#include "Plateau.h"
#include "ControlleurJoueur.h"

class Joueur : public ControlleurJoueur
{
protected:
    std::string nomJoueur;

public:
    explicit Joueur(std::string nom = "tommy");
    ~Joueur();

    std::string getNom() { return nomJoueur; }
};

#endif // JOUEUR_H