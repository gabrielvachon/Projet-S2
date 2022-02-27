#ifndef JOUEUR_H
#define JOUEUR_H

using namespace std;

class Joueur
{
    public:
        Joueur(int pRange, int pMaxHealth);
        ~Joueur();
        void setHealth(int newHealth);
        int getHealth();
        int getMaxHealth();

    private:
        int health;
        int maxHealth;
        int viewRange;

};

#endif