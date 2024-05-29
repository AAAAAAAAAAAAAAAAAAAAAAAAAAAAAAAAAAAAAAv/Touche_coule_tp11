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
    unsigned int* getPosition();
    /**
     * @brief Get the boat direction
     * @return true if vertical, false if horizontal
     */
    bool getDirection();
    void damageBateau();
    bool getBateauState();
    void setBateauSize(unsigned int size);
    unsigned int getBateauSize();
    void setBateauName(std::string name);
    std::string getBateauName();
    bool setBateauAscii(std::string asciiX, std::string asciiY);
    std::string getBateauAscii();
};

#endif