Ce fichier sert de notes communes pour former le compte-rendu.

Choix pour le diagramme de classes:
# Classe Bateau:
### explications générales
La classe Bateau à pour but de simplement contenir les variables nécessaires au fonctionnement des bateaux, avec des simples set et get et aucune réelle logique derrière. L'on a donc considérer les tests unitaires inutiles pour cette classe, les vérifications étant faites par d'autres classes qui contrôlent ensuite ces variables.
###hitPoints
Nous avons choisit de rajouter des hitPoints au bateaux , mais la gestion de quels endroits ont été tirés restent dans classe Tableau. cela limite les vérifications pour un coulé, un simple appel de la fonction donnant l'état, enlevant le besoin de vérifications récursive sur les tableaux.
### Pas de sous classes bateaux:
seuls la taille ainsi que le nom change d'un bateau à l'autre, nous avons donc choisis de les laisser en paramètre de la classe Bateau.
### choix direction / ASCII
Pour simplifier le code, nous avons choisit de ne permettre que deux sens pour le bateau: Horizontal et vertical. Cela nous facilite par la suite la vérification des collisions, ne pouvant être faites que dans un seul sens. 

# classe Plateau:

### explications générales
Cette classe à pour but de gérer, comme son nom l'indique, les plateaux de chaque joueurs. Elle permet donc de demander l'affichage du plateau de tir ou de flotte, gère les couleurs associées (si un bateau à été touché, sa case est écrite en rouge), ainsi que la mise à jour des plateaux. Elle permet aussi de vérifier les collisions, ce qui nous évite de devoir propager les différents paramètres de tailles/ état des cases à d'autres classes. Même si cela resterai plus cohérent avec la méthodologie du reste de la conception, on à trouvé que cela demanderai beaucoup de fonctions intermédiaires pour une logique pas si complexe.

# classe ControlleurJoueur
### explications générales
cette classe sert à toutes les actions qu'un joueur/IA peut avoir sur le jeu. Cela permet donc d'associer à un joueur son plateau, ainsi que ces points de vie (et donc l'état de la partie)
### sous-classe joueur
elle permet tout simplement de rajouter un nom pour identifier le joueur, ainsi que gère l'interface clavier (inutile à l'IA)

### sous-classe  IA
Elle contient tous les calculs internes nécessaires à l'IA basique demandée.
Elle contient donc quelques variables simples: un plateau d'état (tirs effectués, touchés, et cases où ne pas tirer) ainsi que les 2 dernier tirs.
De part la règle supplémentaire des bateaux qui ne peuvent pas être adjacents, on supprime donc systématiquement de la recherche toutes les cases proches d'un set de tirs ayant causé un "coulé" 
Elle permet aussi d'ajouter aléatoirement les bateaux sur la carte.

# classe gestionnaireDeJeu
### explications générales
Sert à passer les différents tours, et donc faire les demandes d'affichages associés ainsi que demandes de retours IA/humains nécessaires

