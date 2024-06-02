#pragma once
#include <vector>
#include <string>
class GestionnaireDeJeu
{
private:
	std::vector<class Joueur*> listeJoueur;
	bool etatPartie;
public:
	GestionnaireDeJeu();
	
	void addPlayer(class Joueur* joueur);
	void ajoutBateau(class Joueur* joueur, std::string type, uint8_t batteauLength);
	
	void passerTour();

};

