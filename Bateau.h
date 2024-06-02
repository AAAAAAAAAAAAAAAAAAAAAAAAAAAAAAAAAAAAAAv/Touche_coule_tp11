#ifndef BATEAU_H
#define BATEAU_H

#include <string>

class Bateau
{
private:

    unsigned int position[2];
    bool direction;
    unsigned int hitPoints;
    unsigned int bateauSize;
    std::string bateauName;
    std::string bateauAscii[2];

public:

    Bateau();
    void setPosition(unsigned int newPosX, unsigned int newPosY);
    /**
     * @brief Get the boat direction
     * @return true if vertical, false if horizontal
     */
    unsigned int* getPosition();
    bool getDirection();
    bool getBateauState();
    unsigned int getBateauSize();
    std::string getBateauName();
    std::string getBateauAscii();

    void damageBateau();

    void setBateauSize(unsigned int size);
    void setBateauName(std::string name);
    bool setBateauAscii(std::string asciiX, std::string asciiY);
};

#endif