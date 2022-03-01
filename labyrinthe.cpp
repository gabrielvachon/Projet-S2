using namespace std; 

#include "labyrinthe.h"
#include "tuile.h"
#include "position.h"
#include <fstream>
#include <string.h>

//--------MODÈLE---------
//# # # # # # # # # # # #
//S - - - - - - - - - - #
//# - # # # T # # - # - #
//# - # C # - # # - # - #
//# - - - # - - # - # # #
//# - # # # # # # - # M #
//# # # # - - # - - # - #
//E - - # # - # - # # - #
//# # - - - - # - # - - #
//# # # T # - # - # - # #
//# - - - # - - - - - # #
//# # # # # # # # # # # #

string tileName;

Labyrinthe::Labyrinthe()
{
    player = new Joueur(1, 100);
    labConstructor("modele1.txt");
}

Labyrinthe::Labyrinthe(string fname)
{
    labConstructor(fname);
}

Labyrinthe::~Labyrinthe()
{
      
}

bool Labyrinthe::mouvement(char c)
{
    int x = 0;
    int y = 0;
    Joueur newPlayerStats;
    switch (c)
    {
        case 'w':
            x = player->getPos().x; //Garder position en X
            y = player->getPos().y - 1; //Décrémenter position en Y
            if(tiles[x][y]->getType() == '#' || y < 0)
            {
                return false;
            }
            else
            {
                tiles[x][y+1]->playerOn = false;
                newPlayerStats = tiles[x][y]->playerEffect(*player);
            }
            break;
        case 'd':
            x = player->getPos().x + 1;
            y = player->getPos().y;
            if(tiles[x][y]->getType() == '#' || x >= xLenght)
            {
                return false;
            }
            else
            {
                tiles[x-1][y]->playerOn = false;
                newPlayerStats = tiles[x][y]->playerEffect(*player);
            }
            break;
        case 's':
            x = player->getPos().x;
            y = player->getPos().y + 1;
            if(tiles[x][y]->getType() == '#' || y > yLenght)
            {
                return false;
            }
            else
            {
                tiles[x][y-1]->playerOn = false;
                newPlayerStats = tiles[x][y]->playerEffect(*player);
            }
            break;
        case 'a':
            x = player->getPos().x - 1;
            y = player->getPos().y;
            if(tiles[x][y]->getType() == '#' || x < 0)
            {
                return false;
            }
            else
            {
                tiles[x+1][y]->playerOn = false;
                newPlayerStats = tiles[x][y]->playerEffect(*player);
            }
            break;
        
        default:
            break;
    }
    *player = newPlayerStats;
    tiles[x][y]->setVisited();
    tiles[x][y]->playerOn = true;
    player->setPos(x,y);
    visibilite(x,y);
    afficherLabyrinthe();
    return true;
}

void Labyrinthe::visibilite(int x, int y)
{
    if(x == 0)
    {
        tiles[x][y+1]->setVisible(true);
        tiles[x][y-1]->setVisible(true);
        tiles[x+1][y+1]->setVisible(true);
        tiles[x+1][y-1]->setVisible(true);
        tiles[x+1][y]->setVisible(true);
    }
    else if(x == xLenght-1)
    {
        tiles[x][y+1]->setVisible(true);
        tiles[x][y-1]->setVisible(true);
        tiles[x-1][y+1]->setVisible(true);
        tiles[x-1][y-1]->setVisible(true);
        tiles[x-1][y]->setVisible(true);
    }
    else
    {
        tiles[x][y+1]->setVisible(true);
        tiles[x][y-1]->setVisible(true);
        tiles[x+1][y+1]->setVisible(true);
        tiles[x+1][y-1]->setVisible(true);
        tiles[x+1][y]->setVisible(true);
        tiles[x-1][y]->setVisible(true);
        tiles[x-1][y+1]->setVisible(true);
        tiles[x-1][y-1]->setVisible(true);
    }
}

position Labyrinthe::getStart()
{
    for (int x = 0; x < xLenght; x++)
    {
        for (int y = 0; y < yLenght; y++)
        {
            if(tiles[x][y]->getType() == 'S')
            {
                position coorStart;
                coorStart.x = x;
                coorStart.y = y;
                return coorStart;
            }
        }
    }
    position coorStart;
    coorStart.x = 0;
    coorStart.y = 0;
    return coorStart;
}

position Labyrinthe::getEnd()
{
    for (int x = 0; x < xLenght; x++)
    {
        for (int y = 0; y < yLenght; y++)
        {
            if(tiles[x][y]->getType() == 'E')
            {
                position coorStart;
                coorStart.x = x;
                coorStart.y = y;
                return coorStart;
            }
        }
    }
    position coorStart;
    coorStart.x = 0;
    coorStart.y = 0;
    return coorStart;
}

void Labyrinthe::labConstructor(string fname)
{
    ifstream file;
    file.open(fname);
    char t;
    string s;
    string nb;
    if(file.is_open())
    {
        getline(file, s);
        for(int k = 0; k < s.size(); k++)
        {
            if(s[k] == ' ')
            {
                xLenght = stoi(nb);
                nb = "";
            }
            else
            {
                nb += s[k];
            }
        }
        yLenght = stoi(nb);
        tiles = new Tuile**[xLenght];
        for (int i = 0; i < yLenght; i++)
        {
            tiles[i] = new Tuile*[yLenght];
        }
        for (int y = 0; y < yLenght; y++)
        {
            for (int x = 0; x < xLenght; x++)
            {
                file.get(t);
                tiles[x][y] = new Tuile(t);
            }
            file.get(t);
        }
    }
    player->setPos(this->getStart().x, this->getStart().y);
    tiles[this->getStart().x][this->getStart().y]->playerOn = true;
    afficherLabyrinthe();
    file.close();
}

Tuile* Labyrinthe::getTile(int x, int y)
{
    return tiles[x][y];
}

void Labyrinthe::afficherLabyrinthe()
{
    system("CLS");
    cout << "===Labyrinthe decouvert===\n";
    for(int y = 0; y < yLenght; y++)
    {
        for(int x = 0; x < xLenght; x++)
        {
            if(tiles[x][y]->playerOn == true)
            {
                cout << 'X' << " ";
            }
            else
            {
                cout << tiles[x][y]->getType() << " ";
            }
        }
        cout << endl;
    }
    cout << "\n===Labyrinthe cache===\n";
    for(int y = 0; y < yLenght; y++)
    {
        for(int x = 0; x < xLenght; x++)
        {
            if(tiles[x][y]->playerOn == true)
            {
                cout << 'X' << " ";
            }
            else if(y == 0 || y == yLenght-1 || x == 0 || x == xLenght-1 || tiles[x][y]->getVisited() == true || tiles[x][y]->getVisible() == true)
            {
                cout << tiles[x][y]->getType() << " ";
            }
            else
            {
                cout << " " << " ";
            }
            
        }
        cout << endl;
    }
    cout << *player << endl << endl;
}