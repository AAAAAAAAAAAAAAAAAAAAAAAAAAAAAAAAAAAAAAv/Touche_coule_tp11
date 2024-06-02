cmake_minimum_required(VERSION 3.5)

project(TOUCHE_COULE_TP11)

set(SOURCE Bateau.cpp 
            ControlleurJoueur.cpp 
            GestionnaireDeJeu.cpp
            IA.cpp
            Plateau.cpp
            TPSMPTouche.cpp
            )

add_executable(TOUCHE_COULE_TP11 ${SOURCE})