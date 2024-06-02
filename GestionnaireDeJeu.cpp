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
	std::cout << "*******BATAILLE NAVALE*******\n\n";
	std::cout << "Nombre de joueurs : 2\n";
	std::cout << "Nombre de bateaux  : 5/joueur\n";
}

void GestionnaireDeJeu::passerTour()
{
}

void GestionnaireDeJeu::ajoutBateau(class Joueur* joueur, std::string type, uint8_t batteauLength)
{
}
