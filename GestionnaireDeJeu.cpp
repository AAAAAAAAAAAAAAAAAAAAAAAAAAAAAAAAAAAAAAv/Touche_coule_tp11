#include "GestionnaireDeJeu.h"
#include "Joueur.h"

GestionnaireDeJeu::GestionnaireDeJeu() : etatPartie(false), listeJoueur(0)
{

}

void GestionnaireDeJeu::addPlayer(class Joueur* joueur)
{
	/* Check the validity of the Joueur address */
	if (nullptr == joueur)
	{
		return;
	}
	
	this->listeJoueur.push_back(joueur);
}

void GestionnaireDeJeu::startGame()
{
	HANDLE couleur_de_console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(couleur_de_console, 27);
	std::cout << "*******BATAILLE NAVALE*******\n\n";
	SetConsoleTextAttribute(couleur_de_console, 15);
	std::cout << "Nombre de joueurs : 2\n";
	std::cout << "Nombre de bateaux  : 5/joueur\n\n";
}

void GestionnaireDeJeu::configure(uint8_t playerIndex, Bateau* const pBateau)
{
	HANDLE couleur_de_console = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(couleur_de_console, 15); 

	if(nullptr == this->listeJoueur[playerIndex])
	{
		std::cerr << "There is no player to this index" << std::endl;
		return;
	}

	std::cout << "------------Console "
			  << this->listeJoueur[playerIndex]->getNom()  
			  <<"------------\n";
	this->listeJoueur[playerIndex]->getPlateau()->drawPlateauFlotte();
	std::cout << std::endl;
	std::cout << "Configuration de Bateau : "; 
	SetConsoleTextAttribute(couleur_de_console, 10); 
	std::cout << pBateau->getBateauName() << std::endl;
	SetConsoleTextAttribute(couleur_de_console, 15); 
	std::cout << "Donnez coordonnee : ";
	SetConsoleTextAttribute(couleur_de_console, 10);

	// Gestion des erreurs a faire
	uint8_t X, Y;
	std::cout << "X => ";
	std::cin >> X;
	std::cout << "                    Y => ";
	std::cin >> Y;
	pBateau->setPosition(X, Y);

	SetConsoleTextAttribute(couleur_de_console, 15);
	std::cout << std::endl;

}

void GestionnaireDeJeu::passerTour()
{
}

void GestionnaireDeJeu::ajoutBateau(class Joueur* joueur, std::string type, uint8_t batteauLength)
{

}
