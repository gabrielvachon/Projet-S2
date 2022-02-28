using namespace std; 

#include "labyrinthe.h"
#include "tuile.h"
#include <fstream>

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

Labyrinthe::Labyrinthe()
{
    //tiles[xLenght][yLenght];
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
    switch (c)
    {
    case 'w':
        x = player->getPos().x;
        y = player->getPos().y - 1;
        if(tiles[x][y]->getType() == '#' || y < 0)
        {
            return false;
        }
        else
        {
            tiles[x][y+1]->setTuile('-');
        }
        break;
    case 'd':
        x = player->getPos().x + 1;
        y = player->getPos().y;
        if(tiles[x][y]->getType() == '#' || x > xLenght)
        {
            return false;
        }
        else
        {
            tiles[x-1][y]->setTuile('-');
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
            tiles[x][y-1]->setTuile('-');
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
            tiles[x+1][y]->setTuile('-');
        }
        break;
    
    default:
        break;
    }
    
    tiles[x][y]->setVisited();
    tiles[x][y]->setTuile('X');
    player->setPos(x,y);
    visibilite(x,y);
    afficherLabyrinthe();
}

void Labyrinthe::visibilite(int x, int y)
{
    for(int y = 0; y < yLenght; y++)
    {
        for(int x = 0; x < xLenght; x++)
        {
            tiles[x][y]->setVisible(false);
        }
    }

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

/*Tuile Labyrinthe::getTile(int x, int y)
{
    return tiles*[x][y];
}

Tuile Labyrinthe::getStart(int x, int y)
{

}

Tuile Labyrinthe::getEnd(int x, int y)
{

}*/

void Labyrinthe::labConstructor(string fname)
{
    ifstream file;
    file.open(fname);
    char t;
    string s;
    string nb;
    player = new Joueur(1, 100);
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
    tiles[player->getPos().x][player->getPos().y]->setTuile('X');
    afficherLabyrinthe();
    file.close();
}

/*Tuile Labyrinthe::getTile(int x, int y)
{
    //return &tiles[x][y];
}*/

void Labyrinthe::afficherLabyrinthe()
{
    cout << "===Labyrinthe decouvert===\n";
    for(int y = 0; y < yLenght; y++)
    {
        for(int x = 0; x < xLenght; x++)
        {
            cout << tiles[x][y]->getType();
        }
        cout << endl;
    }
    cout << "\n===Labyrinthe cache===\n";
    for(int y = 0; y < yLenght; y++)
    {
        for(int x = 0; x < xLenght; x++)
        {
            if(y == 0 || y == yLenght-1 || x == 0 || x == xLenght-1 || tiles[x][y]->getVisited() == true || tiles[x][y]->getVisible() == true)
            {
                cout << tiles[x][y]->getType();
            }
            else
            {
                cout << " ";
            }
            
        }
        cout << endl;
    }
}