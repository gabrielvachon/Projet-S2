#include <iostream>
#include "tuile.h"

class labyrinthe
{
    public:
    labyrinthe();
    ~labyrinthe();

    char getTile(int x, int y);
    void afficherLabyrinthe();
    void labConstructor();

    private:
    int x;
    int y;
    char** tile;
};