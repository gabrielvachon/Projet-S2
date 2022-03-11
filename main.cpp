#include <iostream>
#include <conio.h>
#include "labyrinthe.h"
#include "joueur.h"
#include <string.h>

using namespace std;

int main()
{
    cout << "Testing" << endl;
    Joueur* newPlayer = new Joueur(1, 100);
    string newLabFile = "modele1.txt";
    Labyrinthe lab(/*newLabFile, */newPlayer);
    char dir;
    while((dir = getch()) != 'q')
    {
        lab.mouvement(dir);
    }
    delete newPlayer;
    return 0;
}