#include "labyrinthe.h"
#include "tuile.h"
#include "position.h"
#include <fstream>
#include <string>

using namespace std; 

//--------MODÈLE---------
//# # # # # # # # # # # #
//S - - - - - - - - - - #
//# - # # # T # # - # - #
//# - # H # - # # - # - #
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
    completed = false;
}

Labyrinthe::Labyrinthe(/*const string& pFile,*/ Joueur* pPlayer)
{
    player = pPlayer;
    labConstructor("modele1.txt");
    completed = false;
}

Labyrinthe::~Labyrinthe()
{
      
}

bool Labyrinthe::mouvement(char c)
{
    int x = 0;
    int y = 0;
    int lastX = player->getPos().x;
    int lastY = player->getPos().y;
    Joueur newPlayerStats;
    switch (c)
    {
        case 'w':
            x = player->getPos().x; //Garder position en X
            y = player->getPos().y - 1; //Décrémenter position en Y
            break;
        case 'd':
            x = player->getPos().x + 1;
            y = player->getPos().y;
            break;
        case 's':
            x = player->getPos().x;
            y = player->getPos().y + 1;
            break;
        case 'a':
            x = player->getPos().x - 1;
            y = player->getPos().y;
            break;
        
        default:
            break;
    }

    if(x < 0 || y < 0 || x >= this->xLenght - 1 || y >= this->yLenght - 1 || tiles[x][y]->getType() == '#')
    {
        return false;
    }
    else if(this->getEnd().x == x && this->getEnd().y == y)
    {
        player->setPos(x,y);
        completed = true;
        system("CLS");
        cout << "Winner winner chicken dinner" << endl;
    }
    else
    {
        tiles[lastX][lastY]->playerOn = false;
        tiles[x][y]->playerOn = true;
        newPlayerStats = tiles[x][y]->playerEffect(*player);
        *player = newPlayerStats;
        player->setPos(x,y);
        visibilite(x,y);
        afficherLabyrinthe();
        return true;
    }
    return false;
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

bool Labyrinthe::isCompleted()
{
    return completed;
}