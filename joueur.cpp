#include "joueur.h"
#include "iostream"
#include <string.h>
#include "labyrinthe.h"

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

void Joueur::actif(Labyrinthe*){}
void Joueur::passif(Labyrinthe*){}

Flamingo::Flamingo(int pRange, int pMaxHealth)
{
    this->maxHealth = pMaxHealth;
    this->health = pMaxHealth;
    this->viewRange = pRange;
}
Flamingo::~Flamingo(){}

void Flamingo::actif(Labyrinthe *lab)
{
    health -= 10;
    lab->setMoveWeight(2);
}

void Flamingo::passif(Labyrinthe *lab)
{
    lab->setRayon(2);
}

Jp::Jp(int pRange, int pMaxHealth)
{
    this->maxHealth = pMaxHealth;
    this->health = pMaxHealth;
    this->viewRange = pRange;
}

Jp::~Jp(){}

void Jp::actif(Labyrinthe *lab)
{
    
}

void Jp::passif(Labyrinthe *lab)
{
    
}

Moore::Moore(int pRange, int pMaxHealth)
{
    this->maxHealth = pMaxHealth;
    this->health = pMaxHealth;
    this->viewRange = pRange;
}

Moore::~Moore(){}

void Moore::actif(Labyrinthe *lab)
{

}

void Moore::passif(Labyrinthe *lab)
{
    lab->setHeal(true);
}