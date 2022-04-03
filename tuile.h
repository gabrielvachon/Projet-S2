#ifndef TUILE_H
#define TUILE_H

using namespace std;
#include <iostream>
#include <string.h>
//#include "joueur.h"
class Joueur;

/*
    Classe qui détermine les caractéristiques d'une tuile du labyrinthe.
    Il est possible d'avoir des tuiles de type vide, monstre, piège, trésor, début et fin
    ayant chacun des effets différents.

    S : départ (début du niveau, point de départ du joueur)
    E : fin (termine le niveau, tuile où le joueur doit se rendre)
    M : monstre (enlève de la vie à un passage, doit agiter
    la manette pour éviter la perte de vie supplémentaire,
    cause la mort du joueur si aucune intéraction détectée,
    case monstre disparaît après un passage)(avec accéléromètre)
    T : piège (enlève de la vie à chaque passage)
    H : trésor (joueur regagne un certain nombre de vie)
    # : mur (le joueur ne peu passer sur cette case)
    - : case vide (le joueur est libre d'y circuler sans pénalité
    ou avantages)
*/
class Tuile
{
    public:
        Tuile();
        Tuile(char type);
        ~Tuile(); 
        Tuile & operator = (const Tuile& input);
        friend ostream & operator << (ostream &out, Tuile &tuile)
        {
            return out << tuile.getType();
        }
        string getTypeName();
        char getType();
        Joueur playerEffect(Joueur player); //Applique les effets de la tuile sur le joueur
        void setTuile(char);
        void setVisited();
        bool getVisited();
        void setVisible(bool);
        bool getVisible();
        void setFullHeal(bool);
        bool playerOn;
        
    private:
        char type;
        bool visited;
        bool visible;
        int heal;
};

#endif