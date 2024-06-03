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
	SetConsoleTextAttribute(couleur_de_console, 29);
	std::cout << "*********************BATAILLE NAVALE*********************";
	SetConsoleTextAttribute(couleur_de_console, 15);
	std::cout << "\n\n";
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

	std::cout << "------------Console ";
	SetConsoleTextAttribute(couleur_de_console, 3);
	std::cout << this->listeJoueur[playerIndex]->getNom();
	SetConsoleTextAttribute(couleur_de_console, 15);  
	std::cout <<"------------\n";
	this->listeJoueur[playerIndex]->getPlateau()->drawPlateauTir();
	std::cout << std::endl;
	std::cout << "Configuration de Bateau : "; 
	SetConsoleTextAttribute(couleur_de_console, 10); 
	std::cout << pBateau->getBateauName() << std::endl;
	SetConsoleTextAttribute(couleur_de_console, 15); 
	std::cout << "Donnez coordonnee : ";
	SetConsoleTextAttribute(couleur_de_console, 10);

	// Gestion des erreurs a faire
	int _X, _Y;
	std::cout << " X => ";
	std::cin >> _X;
	std::cout << "                     Y => ";
	std::cin >> _Y;
	if((_X < 0) || (_X > 10) || (_Y < 0) || (_Y > 10))
	{
		std::cerr << "Coor error" << std::endl;
		return;
	}
	pBateau->setPosition(_X, _Y);
	
	std::cout << std::endl;
	SetConsoleTextAttribute(couleur_de_console, 15);
	std::cout << "Donnez direction";
	SetConsoleTextAttribute(couleur_de_console, 10);
	std::cout << " ( 0 => -- ou 1 => | ) : " << std::endl;

	bool direction;
	std::cin >> direction;
	pBateau->setDirection(direction);

	SetConsoleTextAttribute(couleur_de_console, 15);
	std::cout << std::endl;

}

void GestionnaireDeJeu::passerTour()
{
}

void GestionnaireDeJeu::ajoutBateau(class Joueur* joueur, std::string type, uint8_t batteauLength)
{

}
