#include "joueur.h"
#include "iostream"
#include <string.h>

Joueur::Joueur()
{}

Joueur::Joueur(int pRange, int pMaxHealth)
{
    this->maxHealth = pMaxHealth;
    this->health = pMaxHealth;
    this->viewRange = pRange;
}

Joueur::Joueur(const Joueur& joueur)
{
    this->maxHealth = joueur.maxHealth;
    this->health = joueur.health;
    this->viewRange = joueur.viewRange;
    this->pos.x = joueur.pos.x;
    this->pos.y = joueur.pos.y;
}

Joueur::~Joueur()
{}

void Joueur::setHealth(int newHealth)
{
    this->health = newHealth;
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