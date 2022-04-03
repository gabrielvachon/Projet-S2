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
    ray = 1;
    moveWeight = 1;
    labConstructor("modele1.txt");
    completed = false;
}

Labyrinthe::Labyrinthe(/*const string& pFile,*/ Joueur* pPlayer)
{
    player = pPlayer;
    ray = 1;
    moveWeight = 1;
    heal = false;
    labConstructor("modele1.txt");
    completed = false;
    player->passif(this);
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
    char type;
    if(c == '1')
    {
        player->actif(this);
    }
    switch (c)
    {
        case 'w':
            x = player->getPos().x; //Garder position en X
            y = player->getPos().y - moveWeight; //Décrémenter position en Y
            break;
        case 'd':
            x = player->getPos().x + moveWeight;
            y = player->getPos().y;
            break;
        case 's':
            x = player->getPos().x;
            y = player->getPos().y + moveWeight;
            break;
        case 'a':
            x = player->getPos().x - moveWeight;
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
        type = tiles[x][y]->getType();
        if(type == 'H')
        {
            tiles[x][y]->setFullHeal(heal);
        }
        tiles[lastX][lastY]->playerOn = false;
        tiles[x][y]->playerOn = true;
        newPlayerStats = tiles[x][y]->playerEffect(*player);
        *player = newPlayerStats;
        player->setPos(x,y);
        visibilite(x,y);
        afficherLabyrinthe();
        moveWeight = 1;
        return true;
    }
    return false;
}

void Labyrinthe::visibilite(int x, int y)
{
    int ray_up = ray;
    int ray_down = ray;
    int ray_left = ray;
    int ray_right = ray;

    for(int i = 1; i <= ray; i++)
    {
        if(x - ray_left < 0)
        {
            ray_left--;
        }
        if(x + ray_right > xLenght-1)
        {
            ray_right--;
        }
        if(y - ray_up < 0)
        {
            ray_up--;
        }
        if(y + ray_down > yLenght-1)
        {
            ray_down--;
        }
    }
    for(int i = 1; i <= ray_left; i++)
    {
        if(i <= ray_up)
        {
            tiles[x-i][y-i]->setVisible(true);
        }
        tiles[x-i][y]->setVisible(true);
        if(i <= ray_down)
        {
            tiles[x-i][y+i]->setVisible(true);
        }
    }
    for(int i = 1; i <= ray_right; i++)
    {
        if(i <= ray_up)
        {
            tiles[x+i][y-i]->setVisible(true);
        }
        tiles[x+i][y]->setVisible(true);
        if(i <= ray_down)
        {
            tiles[x+i][y+i]->setVisible(true);
        }
    }
    for(int i = 1; i <= ray_up; i++)
    {
        for(int j = 1; j <= ray_left; j++)
        {
            tiles[x-j][y-i]->setVisible(true);
        }
        tiles[x][y-i]->setVisible(true);
        for(int j = 1; j <= ray_right; j++)
        {
            tiles[x+j][y-i]->setVisible(true);
        }
    }
    for(int i = 1; i <= ray_down; i++)
    {
        tiles[x][y+i]->setVisible(true);
        for(int j = 1; j <= ray_left; j++)
        {
            tiles[x-j][y+i]->setVisible(true);
        }
        for(int j = 1; j <= ray_right; j++)
        {
            tiles[x+j][y+i]->setVisible(true);
        }
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
    if(x < 0 || x < xLenght-1 || y < 0 || y > yLenght-1)
        return NULL;
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

void Labyrinthe::setRayon(int r)
{
    ray = r;
}

void Labyrinthe::setMoveWeight(int m)
{
    moveWeight = m;
}

void Labyrinthe::setHeal(bool h)
{
    heal = h;
}

bool Labyrinthe::isCompleted()
{
    return completed;
}