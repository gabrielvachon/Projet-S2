#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <iostream>
#include "tuile.h"
#include <vector>

using namespace std;

class Labyrinthe
{
    public:
        Labyrinthe();
        Labyrinthe(bool test); //Constructeur d'un labyrinthe prédéfini
        ~Labyrinthe();

        //Tuile getTile(int x, int y); //Retourne la case désirée
        //Tuile getStart(); //Retourne la case départ
        //Tuile getEnd(); //Retourne la case de fin
        void afficherLabyrinthe(); //Afficher le labyrinthe
        void labConstructor();
        //int getXLenght(); //Retourne longueur du labyrinthe
        //int getYLenght(); //Retourne largeur du labyrinthe

    private:
        int xLenght;
        int yLenght;
        Tuile*** tiles; //Tableau de tuiles
};

#endif