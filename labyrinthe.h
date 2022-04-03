#ifndef LABYRINTHE_H
#define LABYRINTHE_H

#include <iostream>
#include "tuile.h"
#include "joueur.h"
#include <string.h>

using namespace std;

class Labyrinthe
{
    public:
        Labyrinthe();
        Labyrinthe(/*const string&,*/Joueur*); //Constructeur d'un labyrinthe prédéfini
        ~Labyrinthe();

        Tuile* getTile(int x, int y); //Retourne la case désirée
        position getStart(); //Retourne la case départ
        position getEnd(); //Retourne la case de fin
        void afficherLabyrinthe(); //Afficher le labyrinthe
        void labConstructor(string);
        bool mouvement(char);
        void visibilite(int, int);
        bool isCompleted();
        void setRayon(int);
        void setMoveWeight(int);
        void setHeal(bool);
        //int getXLenght(); //Retourne longueur du labyrinthe
        //int getYLenght(); //Retourne largeur du labyrinthe

    private:
        int xLenght;
        int yLenght;
        int moveWeight;
        int ray;
        bool heal;
        Tuile*** tiles; //Tableau de tuiles
        Joueur *player;
        bool completed;
};

#endif