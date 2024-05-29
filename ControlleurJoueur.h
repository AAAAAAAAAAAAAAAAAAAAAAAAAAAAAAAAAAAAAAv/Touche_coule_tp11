#ifndef CONTROLLEURJOUEUR_H
#define CONTROLLEURJOUEUR_H

class ControlleurJoueur
{
protected:
    unsigned int hitPoint;
    class Plateau* pPlateau;

public:
    ControlleurJoueur();
    ~ControlleurJoueur() = default;
    void setPlateau(class Plateau* plateau);
    class Plateau* getPlateau();
    bool tir(Plateau* plateau, unsigned int x, unsigned int y);
    unsigned int getHitPoints();
};

#endif // CONTROLLEURJOUEUR_H