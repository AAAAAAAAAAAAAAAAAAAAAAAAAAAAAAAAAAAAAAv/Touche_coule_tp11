#pragma once
#include <cinttypes>
#include "Bateau.h"

/**
 * @brief
 */
class Plateau
{
private:
	/**
	 * @brief
	 */
	uint8_t row = 10, columns = 10;

	/**
	 * @brief Plateau de tir masterclass akhi
	 */
	char** plateauTir;

	/**
	 * @brief AVC mdr
	 */
	class Bateau*** plateauFlotte;

public:
	Plateau(uint8_t row = 10, uint8_t columns = 10);
	~Plateau();

	uint8_t getRow();
	uint8_t getColumns();

	void tir(uint8_t row, uint8_t columns);
	char touche(uint8_t row, uint8_t columns);

	bool ajoutBateau(class Bateau* bateau, uint8_t row, uint8_t columns);

	void drawPlateauTir();
	void drawPlateauFlotte();
};

