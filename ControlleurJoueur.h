#ifndef CONTROLLEURJOUEUR_H
#define CONTROLLEURJOUEUR_H

class ControllerJoueur
{
protected:
    unsigned int hitPoint;
    class Plateau* pPlateau;

public:
    ControlleurJoueur();
    ~ControllerJoueur() = default;
    void setPlateau(class Plateau* plateau);
    class Plateau* getPlateau();
    bool tir(Plateau* plateau, unsigned int x, unsigned int y);
    unsigned int getHitPoints();
};

#endif // CONTROLLEURJOUEUR_H