#ifndef IA_H
#define IA_H

#include <vector>

enum class Etat 
{
    Toucher = 0,
    PasToucher = 1, 
};

class IA : public ControlleurJoueur 
{

protected:
std::vector<int> dernierTir;

public:
    IA();

    void ajouterBateau(class Bateau* bateau, unsigned int x, unsigned int y);
    void jouer();
};

#endif // IA_H