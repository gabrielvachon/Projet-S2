#include "labyrinthe.h"

labyrinthe::labyrinthe()
{
    x = 30;
    y = 30;
    tile[x][y];
    labConstructor();
}

labyrinthe::~labyrinthe()
{

}

void labyrinthe::labConstructor()
{
    
}

char labyrinthe::getTile(int i, int j)
{
    return tile[i][j];
}

void labyrinthe::afficherLabyrinthe()
{
    for(int i = 0; i < x; i++)
    {
        for(int j = 0; j < y; j++)
        {
            cout << tile[i][j];
        }
        cout << std::endl;
    }
}