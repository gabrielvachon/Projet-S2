#include <iostream>
#include <conio.h>
#include "labyrinthe.h"
#include "joueur.h"
#include <string.h>


using namespace std;

int main()
{
    cout << "Testing" << endl;
    Labyrinthe lab;

    char dir;
    while((dir = getch()) != 'q')
    {
        lab.mouvement(dir);
    }
    return 0;
}