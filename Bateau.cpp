#include "Bateau.h"
using std::string;
Bateau::Bateau()
{
    position[0] = -1;
    position[1] = -1;
    direction = 0;
    hitPoints = 0;
    bateauSize = 0;
    bateauName = "";
    bateauAscii[0] = "";
    bateauAscii[1] = "";
}

Bateau::Bateau(Bateau const& autre)
{
    position[0] = -1;
    position[1] = -1;
    direction = 0;
    hitPoints = autre.hitPoints;
    bateauSize = autre.bateauSize;
    bateauName = autre.bateauName;
    bateauAscii[0] = autre.bateauAscii[0];
    bateauAscii[1] = autre.bateauAscii[1];
}

void Bateau::setPosition(unsigned int newPosX, unsigned int newPosY)
{
    position[0] = newPosX;
    position[1] = newPosY;
}
unsigned int* Bateau::getPosition()
{
    return position;
}

bool Bateau::getDirection()
{
    return this->direction;
}

void Bateau::damageBateau()
{
    if (hitPoints > 0)
    {
        hitPoints--;
    }
}
bool Bateau::getBateauState()
{
    return hitPoints;
}
void Bateau::setBateauSize(unsigned int size)
{
    bateauSize = size;
}
unsigned int Bateau::getBateauSize()
{
    return bateauSize;
}
void Bateau::setBateauName(std::string name)
{
    bateauName = name;
}
std::string Bateau::getBateauName()
{
    return bateauName;
}
bool Bateau::setBateauAscii(std::string asciiX, std::string asciiY)
{
    if (asciiX.size() == asciiY.size() && asciiX.size() == bateauSize + 1)
    {
        bateauAscii[0] = asciiX;
        bateauAscii[1] = asciiY;
        return 1;
    }
    return 0;
}