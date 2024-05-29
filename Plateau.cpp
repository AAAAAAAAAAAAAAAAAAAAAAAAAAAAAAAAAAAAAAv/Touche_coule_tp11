#include "Plateau.h"
#include <iostream>

/**
 * @brief Allocates a 2D array of the specified type and dimensions.
 *
 * This function allocates a 2D array with the given number of rows and columns.
 * It returns a pointer to the allocated 2D array. If any allocation fails, it
 * returns nullptr.
 *
 * @tparam Type The type of elements to be stored in the array.
 * @param row The number of rows in the 2D array.
 * @param columns The number of columns in the 2D array.
 * @return Type** A pointer to the allocated 2D array. Returns nullptr if allocation fails.
 */
template <class Type>
Type** Alloc2DArray(uint8_t row, uint8_t columns)
{
	Type** pArray  = new Type*[row];

	/* Check for invalid allocation */
	if (nullptr == pArray) return nullptr;

	for (int i = 0; i < row; i++)
	{
		Type* newArray = new Type[columns];

		if (nullptr == newArray)
		{
			/* Invalid Allocation */
			return nullptr;
		}

		memset(newArray, 0, (sizeof(Type) * columns));

		/* Set the current row pointer to the newly created array */
		pArray[i] = newArray;
	}

	return pArray;
}
template <class Type>
bool Free2DArray(Type** pArray, uint8_t row, uint8_t columns)
{
	if (nullptr == pArray)
	{
		return false;
	}

	for (int i = 0; i < row; i++)
	{

		Type* currentColumn = pArray[i];
		if (nullptr == currentColumn)
		{
			/* Invalid Allocation */
			return false;
		}

		delete[] currentColumn;
	}
	delete[] pArray;
	return true;
}

Plateau::Plateau(uint8_t _row, uint8_t _columns) : row(_row), columns(_columns)
{
	this->plateauTir = Alloc2DArray<char>(this->row, this->columns);

	if (nullptr == this->plateauTir)
	{
		*(int*)0 = 0; //xD
	}

	this->plateauFlotte = Alloc2DArray<class Bateau*>(this->row, this->columns);

	if (nullptr == this->plateauFlotte)
	{
		return;
	}
}

Plateau::~Plateau()
{
	Free2DArray(this->plateauFlotte, this->row, this->columns);
	Free2DArray(this->plateauTir, this->row, this->columns);
}

uint8_t Plateau::getRow()
{
	return this->row;
}

uint8_t Plateau::getColumns()
{
	return this->columns;
}

void Plateau::tir(uint8_t row, uint8_t columns)
{

}

char Plateau::touche(uint8_t row, uint8_t columns)
{
	return '0';
}

bool Plateau::ajoutBateau(class Bateau* bateau, uint8_t row, uint8_t columns) 
{
	/* Check the validity of the 'Bateau' pointer */
	if (nullptr == bateau)
	{
		return false;
	}

	unsigned int* position = bateau->getPosition();

	/* Check if the position 2d array is valid */
	if(nullptr == position)
	{
		// Y'a aucun monde où ça arrives
		return false;
	}

	/* Check if the boat position is valid */
	if (position[0] == -1 || position[1] == -1)
	{
		return false;
	}

	bool direction = bateau->getDirection();

	unsigned int bateauSize = bateau->getBateauSize();
	return false;
}


void Plateau::drawPlateauTir()
{
	// Check if map pointer is valid
	if (nullptr == this->plateauTir) return;

	// First case empty
	printf("   |");

	// Draw Header line with its letter
	for (int i = 0; i < this->columns; i++)
	{
		printf("%2c |", 'A' + i);
	}

	// Draw each row
	for (int i = 0; i < this->row; i++)
	{
		// Draw Row number
		printf("\n%2d |", i + 1);

		// Draw each collumns
		for (int k = 0; k < this->columns; k++)
		{
			// Todo define case status
			char caseStatusChar = ' ';
			char currentCase = this->plateauTir[i][k];

			caseStatusChar = ' ';
			printf("%2c |", caseStatusChar);
		}
	}

	// Separate
	printf("\n\n");
}

void Plateau::drawPlateauFlotte()
{

}
