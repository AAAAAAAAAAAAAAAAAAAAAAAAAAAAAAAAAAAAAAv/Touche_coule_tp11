/*


 /$$$$$$$              /$$               /$$ /$$ /$$                 /$$   /$$                               /$$          
| $$__  $$            | $$              |__/| $$| $$                | $$$ | $$                              | $$          
| $$  \ $$  /$$$$$$  /$$$$$$    /$$$$$$  /$$| $$| $$  /$$$$$$       | $$$$| $$  /$$$$$$  /$$    /$$ /$$$$$$ | $$  /$$$$$$ 
| $$$$$$$  |____  $$|_  $$_/   |____  $$| $$| $$| $$ /$$__  $$      | $$ $$ $$ |____  $$|  $$  /$$/|____  $$| $$ /$$__  $$
| $$__  $$  /$$$$$$$  | $$      /$$$$$$$| $$| $$| $$| $$$$$$$$      | $$  $$$$  /$$$$$$$ \  $$/$$/  /$$$$$$$| $$| $$$$$$$$
| $$  \ $$ /$$__  $$  | $$ /$$ /$$__  $$| $$| $$| $$| $$_____/      | $$\  $$$ /$$__  $$  \  $$$/  /$$__  $$| $$| $$_____/
| $$$$$$$/|  $$$$$$$  |  $$$$/|  $$$$$$$| $$| $$| $$|  $$$$$$$      | $$ \  $$|  $$$$$$$   \  $/  |  $$$$$$$| $$|  $$$$$$$
|_______/  \_______/   \___/   \_______/|__/|__/|__/ \_______/      |__/  \__/ \_______/    \_/    \_______/|__/ \_______/
                                                                                                                          

 /$$                        /$$                                           
| $$                       |__/                                           
| $$       /$$$$$$ /$$   /$$/$$ /$$$$$$$                                  
| $$      /$$__  $| $$  | $| $$/$$_____/                                  
| $$     | $$  \ $| $$  | $| $|  $$$$$$                                   
| $$     | $$  | $| $$  | $| $$\____  $$                                  
| $$$$$$$|  $$$$$$|  $$$$$$| $$/$$$$$$$/                                  
|_/$$$$$$/\______/ /$$/$$/$$__|_______/                                   
 /$$__  $$        |__| $| $$                                              
| $$  \__//$$   /$$/$| $| $$ /$$$$$$ /$$   /$$/$$$$$$/$$$$  /$$$$$$       
| $$ /$$$| $$  | $| $| $| $$|____  $| $$  | $| $$_  $$_  $$/$$__  $$      
| $$|_  $| $$  | $| $| $| $$ /$$$$$$| $$  | $| $$ \ $$ \ $| $$$$$$$$      
| $$  \ $| $$  | $| $| $| $$/$$__  $| $$  | $| $$ | $$ | $| $$_____/      
|  $$$$$$|  $$$$$$| $| $| $|  $$$$$$|  $$$$$$| $$ | $$ | $|  $$$$$$$      
 \/$$$$$$ \______/|__|__|__/\_______/\_/$$__/|/$$ |__/ |__/\_______/      
 /$$__  $$                            | $$   |__/                         
| $$  \ $$/$$   /$$ /$$$$$$ /$$$$$$$ /$$$$$$  /$$/$$$$$$$                 
| $$  | $| $$  | $$/$$__  $| $$__  $|_  $$_/ | $| $$__  $$                
| $$  | $| $$  | $| $$$$$$$| $$  \ $$ | $$   | $| $$  \ $$                
| $$/$$ $| $$  | $| $$_____| $$  | $$ | $$ /$| $| $$  | $$                
|  $$$$$$|  $$$$$$|  $$$$$$| $$  | $$ |  $$$$| $| $$  | $$                
 \____ $$$\______/ \_______|__/  |__/  \___/ |__|__/  |__/                
      \__/                                                                
                                                                                                            
*/


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
	— 1 torpilleur (ligne de 2 cases)
	il y a deux torpilleurs pour chaque joueur
	11 -> joueur 1 torpilleur 1 (pareil pour 12)
	*/

	Bateau* pCroiseur1 = nullptr;
	Bateau* pPorteAvion1 = nullptr;
	Bateau* pContreTorpilleur11 = nullptr;
	Bateau* pContreTorpilleur12 = nullptr;
	Bateau* pTorpilleur1 = nullptr;
	
	std::vector<Bateau*> tabBateau {
		pPorteAvion1,
		pCroiseur1,
		pContreTorpilleur11,
		pContreTorpilleur12,
		pTorpilleur1
	};
	/*
	tabBateau[0] = pPorteAvion1;
	tabBateau[1] = pCroiseur1;
	tabBateau[2] = pContreTorpilleur11;
	tabBateau[3] = pContreTorpilleur12;
	tabBateau[4] = pTorpilleur1;
	*/
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

	// initialisation des tailles de bateaux

	pPorteAvion1->setBateauSize(5);
	pCroiseur1->setBateauSize(4);
	pContreTorpilleur11->setBateauSize(3);
	pContreTorpilleur12->setBateauSize(3);
	pTorpilleur1->setBateauSize(2);

	pPorteAvion1->setBateauName("Porte Avion");
	pCroiseur1->setBateauName("Croiseur");
	pContreTorpilleur11->setBateauName("Contre Torpilleur 1");
	pContreTorpilleur12->setBateauName("Contre Torpilleur 2");
	pTorpilleur1->setBateauName("Torpilleur");
	
	Bateau* pPorteAvion2 = new Bateau(*pPorteAvion1);
	Bateau* pCroiseur2 = new Bateau(*pCroiseur1);
	Bateau* pContreTorpilleur21 = new Bateau(*pContreTorpilleur11);
	Bateau* pContreTorpilleur22 = new Bateau(*pContreTorpilleur12);
	Bateau* pTorpilleur2 = new Bateau(*pTorpilleur1);

	tabBateau.push_back(pPorteAvion2);
	tabBateau.push_back(pCroiseur2);
	tabBateau.push_back(pContreTorpilleur21);
	tabBateau.push_back(pContreTorpilleur22);
	tabBateau.push_back(pTorpilleur2);

	pGameManager->startGame();
	pGameManager->configure();
	/*
	std::cout << "*******BATAILLE NAVALE*******\n\n";
	std::cout << "Nombre de joueurs : 2\n";
	std::cout << "Nombre de bateaux  : 5/joueur\n";

	for(int i = 0; i < 9; i++)
	{	
		std::cout << "------------Console Joueur 1------------\n"
		std::cout << "Plateau de 
		std::cout << "----------------------------------------"
		pPlateau1->drawPlateauTir();
	}
	pPlateau1->drawPlateauTir();
	*/


	// Liberer Memoire
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
