#ifndef JOUEUR_H
#define JOUEUR_H

using namespace std;

struct position
{
    int x = 0;
    int y = 1;
};

class Joueur
{
    public:
        Joueur(int pRange, int pMaxHealth);
        ~Joueur();
        void setHealth(int newHealth);
        int getHealth();
        int getMaxHealth();
        void setPos(int,int);
        position getPos();

    private:
        int health;
        int maxHealth;
        int viewRange;
        position pos;
        
};



#endif