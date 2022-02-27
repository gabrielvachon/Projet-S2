using namespace std; 

#include "labyrinthe.h"
#include "tuile.h"

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
    labConstructor();
}

Labyrinthe::Labyrinthe(bool test) : xLenght(12), yLenght(12)
{
    cout << "New laby";
    tiles = new Tuile**[xLenght];
    for (int i = 0; i < yLenght; i++)
    {
        tiles[i] = new Tuile*[yLenght];
    }
    for (int x = 0; x < xLenght; x++)
    {
        for (int y = 0; y < yLenght; y++)
        {
            tiles[x][y] = new Tuile('#');
        }
        
    }
    
}

Labyrinthe::~Labyrinthe()
{
    cout << "bye bye";    
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

void Labyrinthe::labConstructor()
{

}

/*Tuile Labyrinthe::getTile(int x, int y)
{
    //return &tiles[x][y];
}*/

void Labyrinthe::afficherLabyrinthe()
{
    for(int x = 0; x < xLenght; x++)
    {
        for(int y = 0; y < yLenght; y++)
        {
            //cout << tiles[x][y];
        }
        cout << endl;
    }
}