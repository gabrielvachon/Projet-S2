using namespace std;

#include <iostream>
#include <string.h>
#include <random>
#include "tuile.h"
#include "joueur.h"
#include <thread>
#include <chrono>
#include <conio.h>

bool fight;

Tuile::Tuile() : visible(false) {
    heal = rand() % 50 + 20;
}

Tuile::Tuile(char typeTuile)
: type(typeTuile), visible(false) {
    heal = rand() % 50 + 20;
}

Tuile::~Tuile() {}

string Tuile::getTypeName()
{
    switch (type)
    {
        case 'S':
            return "Départ";
            break;

        case 'X':
            return "Joueur";
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

        case 'H':
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

void Tuile::setTuile(char c)
{
    type = c;
}

void timer()
{
    this_thread::sleep_for(3s);
    fight = false;
}

Joueur Tuile::playerEffect(Joueur player)
{
    int damage;
    int factor = 100;
    switch (this->type)
    {
        case 'M':
        {
            cout << "===FIGHT===";
            fight = true;
            thread time1(timer);
            bool fightInit = true;
            char lastInput = 0;
            char keyInput = 0;
            while(fight)
            {
                while (kbhit())
                {
                    keyInput = getch();
                    if(keyInput == 'a' || keyInput == 'd')
                    {
                        if(fightInit)
                        {
                            lastInput = keyInput;
                            fightInit = false;
                            factor-=2;
                        }
                        else
                        {
                            if(keyInput == 'a' && lastInput == 'd')
                            {
                                lastInput = 'a';
                                factor-=2;
                            }
                            else if(keyInput == 'd' && lastInput == 'a')
                            {
                                lastInput = 'd';
                                factor-=2;
                            }
                        }
                    }
                }
                this_thread::sleep_for(25ms);
            }
            time1.join();
            srand((unsigned int)time(NULL));
            damage = rand()%factor;
            cout<<damage<< " " << factor;
            if((player.getHealth() - damage) < 0)
            {
                player.setHealth(0);
            }
            else
            {
                player.setHealth(player.getHealth() - damage);
            }
            type = '-';
            break;
        }

        case 'T':
            damage = rand() % 20 + 5;
            if((player.getHealth() - damage) < 0)
            {
                player.setHealth(0);
            }
            else
            {
                player.setHealth(player.getHealth() - damage);
            }
            break;

        case 'H':
            if((player.getHealth() + heal) > player.getMaxHealth())
            {
                player.setHealth(player.getMaxHealth());
            }
            else
            {
                player.setHealth(player.getHealth() + heal);
            }
            type = '-';
            break;

        default:
            break;
    }
    return player;
}

void Tuile::setVisited()
{
    visited = true;
}

bool Tuile::getVisited()
{
    return visited;
}

void Tuile::setVisible(bool v)
{
    visible = v;
}

bool Tuile::getVisible()
{
    return visible;
}

void Tuile::setFullHeal(bool h)
{
    if(h == true)
        heal = 100;
}

Tuile & Tuile::operator = (const Tuile& input)
{
    this->type = input.type;
    return *this;
}