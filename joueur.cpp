#include "joueur.h"

Joueur::Joueur(int pRange, int pMaxHealth)
{

}

Joueur::~Joueur()
{

}

void Joueur::setHealth(int newHealth)
{

}

int Joueur::getHealth()
{
    return this->health;
}

int Joueur::getMaxHealth()
{
    return this->maxHealth;
}

void Joueur::setPos(int x1, int y1)
{
    pos.x = x1;
    pos.y = y1;
}

position Joueur::getPos()
{
    return pos;
}