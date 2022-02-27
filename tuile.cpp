using namespace std;
#include <iostream>
#include <string.h>
#include <random>
#include "tuile.h"

Tuile::Tuile()
{}

Tuile::Tuile(char typeTuile)
: type(typeTuile) {}

Tuile::~Tuile() {}

string Tuile::getTypeName()
{
    switch (type)
    {
        case 'S':
            return "Départ";
            break;

        case 'E':
            return "Fin";
            break;
        
        case 'M':
            return "Monstre";
            break;
        
        case 'T':
            return "Piège";
            break;

        case 'C':
            return "Trésor";
            break;

        case '#':
            return "Mur";
            break;

        case '-':
            return "Vide";
            break;
    }
    return NULL;
}

char Tuile::getType()
{
    return type;
}

void Tuile::playerEffect(Joueur player)
{
    int damage;
    int factor;
    switch (this->type)
    {
        case 'M':
            factor = 100; //Facteur à définir avec mouvement de l'accéléromètre
            damage = rand() % factor;
            if((player.getHealth()) - damage < 0)
            {
                player.setHealth(0);
            }
            type = '-';
            break;
        
        case 'T':
            damage = rand() % 20 + 5;
            if((player.getHealth() - damage) < 0)
            {
                player.setHealth(0);
            }
            break;

        case 'C':
            int heal = rand() % 50 + 20;
            if((player.getHealth() + heal) > player.getMaxHealth())
            {
                player.setHealth(player.getMaxHealth());
            }
            break;
            
        default:
            break;
    }
}

Tuile & Tuile::operator = (const Tuile& input)
{
    this->type = input.type;
    return *this;
}