#ifndef JOUEUR_H
#define JOUEUR_H

using namespace std;

#include <iostream>
#include <string.h>
#include "position.h"
#include "labyrinthe.h"
class Labyrinthe;

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
        virtual void actif(Labyrinthe*);
        virtual void passif(Labyrinthe*);
        position getPos();
        friend ostream & operator << (ostream &out, const Joueur &joueur)
        {
            return out << "Health : " << joueur.health << "/" << joueur.maxHealth;
        }

    protected:
        int health;
        int maxHealth;
        int viewRange;
        position pos;  
};

class Flamingo : public Joueur
{
    public:
        Flamingo(int pRange, int pMaxHealth);
        ~Flamingo();
        void passif(Labyrinthe *lab);
        void actif(Labyrinthe *lab);
    private:
};

class Jp : public Joueur
{
    public:
        Jp(int pRange, int pMaxHealth);
        ~Jp();
        void passif(Labyrinthe *lab);
        void actif(Labyrinthe *lab);
    private:
};

class Moore : public Joueur
{
    public:
        Moore(int pRange, int pMaxHealth);
        ~Moore();
        void passif(Labyrinthe *lab);
        void actif(Labyrinthe *lab);
    private:
};

#endif