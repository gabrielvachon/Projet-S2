#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <iostream>
#include "tuile.h"
#include "joueur.h"
#include <vector>
#include <string>

using namespace std;

class Labyrinthe
{
    public:
        Labyrinthe();
        Labyrinthe(string); //Constructeur d'un labyrinthe prédéfini
        ~Labyrinthe();

        Tuile* getTile(int x, int y); //Retourne la case désirée
        position getStart(); //Retourne la case départ
        position getEnd(); //Retourne la case de fin
        void afficherLabyrinthe(); //Afficher le labyrinthe
        void labConstructor(string);
        bool mouvement(char);
        void visibilite(int, int);
        //int getXLenght(); //Retourne longueur du labyrinthe
        //int getYLenght(); //Retourne largeur du labyrinthe

    private:
        bool fight;
        int xLenght;
        int yLenght;
        Tuile*** tiles; //Tableau de tuiles
        Joueur *player;
};

#endif