#ifndef JOUEUR_H
#define JOUEUR_H

#include <string>

class Joueur
{
protected:
    std::string nomJoueur;

public:
    explicit Joueur(std::string nom = "tommy");
    

};

#endif // JOUEUR_H