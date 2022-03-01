#ifndef JOUEUR_H
#define JOUEUR_H

using namespace std;

#include <iostream>
#include <string.h>
#include "position.h"

class Joueur
{
    public:
        Joueur();
        Joueur(int pRange, int pMaxHealth);
        Joueur(const Joueur&); //Copy constructor
        ~Joueur();
        void setHealth(int newHealth);
        int getHealth();
        int getMaxHealth();
        void setPos(int,int);
        position getPos();
        friend ostream & operator << (ostream &out, const Joueur &joueur)
        {
            return out << "Health : " << joueur.health << "/" << joueur.maxHealth;
        }

    private:
        int health;
        int maxHealth;
        int viewRange;
        position pos;        
};



#endif