#pragma once
#include <iostream>
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
	
	void startGame();// démarre le jeu avec un message
	void configure();// les joueurs donne les positions des boat en début de game
	void passerTour();

};

