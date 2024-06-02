// TPSMPTouche.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include "GestionnaireDeJeu.h"
#include "Plateau.h"
#include "Joueur.h"

int main()
{
	
	Joueur* pPlayerOne = new Joueur("Eric Zemmour");
	if (nullptr == pPlayerOne)
	{
		std::cerr << "Failed to create a Joueur object" << std::endl;
		return EXIT_FAILURE;
	}

	Joueur* pPlayerTwo = new Joueur("Marine Le Pen");
	if (nullptr == pPlayerTwo)
	{
		std::cerr << "Failed to create a Joueur object" << std::endl;
		return EXIT_FAILURE;
	}

	GestionnaireDeJeu* pGameManager = new GestionnaireDeJeu;
	pGameManager->addPlayer(pPlayerOne);
	pGameManager->addPlayer(pPlayerTwo);

	Plateau* pPlateau1 = new Plateau(10, 10);
	if (nullptr == pPlateau1)
	{
		std::cerr << "Failed to create a Plateau object" << std::endl;
		return EXIT_FAILURE;
	}

	Plateau* pPlateau2 = new Plateau(10, 10);
	if (nullptr == pPlateau2)
	{
		std::cerr << "Failed to create a Plateau object" << std::endl;
		return EXIT_FAILURE;
	}

	pPlayerOne->setPlateau(pPlateau1);
	pPlayerTwo->setPlateau(pPlateau2);
	
	/*
	— 1 porte-avion (ligne de 5 cases),
	— 1 croiseur (ligne de 4 cases),
	— 2 contre-torpilleurs (ligne de 3 cases),
	— 1 torpilleur (ligne de 2 cases).
	*/

	Bateau* tabBateau[5];

	Bateau* pPorteAvion1 = nullptr;
	tabBateau[0] = pPorteAvion1;
	Bateau* pCroiseur1 = nullptr;
	tabBateau[1] = pCroiseur1;
	Bateau* pContreTorpilleur11 = nullptr;
	// il y a deux torpilleurs pour chaque joueur
	// 11 -> joueur 1 torpilleur 1 (pareil pour 12)
	tabBateau[2] = pContreTorpilleur11;
	Bateau* pContreTorpilleur12 = nullptr;
	tabBateau[3] = pContreTorpilleur12;
	Bateau* pTorpilleur1 = nullptr;
	tabBateau[4] = pTorpilleur1;

	std::for_each(std::begin(tabBateau), 
				  std::end(tabBateau), 
				  [&](auto*& element) -> int {

					element = new Bateau();
					if(nullptr == element)
					{
						std::cerr << "Failed to create a Bateau object" << std::endl;
						return EXIT_FAILURE;
					}
				});

	pPorteAvion1->setBateauSize(5);
	pCroiseur1->setBateauSize(4);
	pContreTorpilleur11->setBateauSize(3);
	pContreTorpilleur12->setBateauSize(3);
	pTorpilleur1->setBateauSize(2);

	

	/*
	Bateau* pPorteAvion2 = nullptr;
	tabBateau[1] = pPorteAvion2;
	Bateau* pCroiseur2 = nullptr;
	tabBateau[3] = pCroiseur2;
	Bateau* pContreTorpilleur21 = nullptr;
	tabBateau[6] = pContreTorpilleur21;
	Bateau* pContreTorpilleur22 = nullptr;
	tabBateau[7] = pContreTorpilleur22;
	Bateau* pTorpilleur2 = nullptr;
	tabBateau[9] = pTorpilleur2;
	*/

	pPlateau1->drawPlateauTir();

	delete pPlayerOne;
	delete pPlayerTwo;
	delete pGameManager;
	delete pPlateau1;
	delete pPlateau2;

	std::for_each(std::begin(tabBateau), 
				  std::end(tabBateau), 
				  [&](auto*& element) -> void {

					delete element;
					element = nullptr;
				});
												


	return EXIT_SUCCESS;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
