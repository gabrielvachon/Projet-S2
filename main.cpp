#include <iostream>
#include <conio.h>
#include "labyrinthe.h"
#include "joueur.h"
#include <string.h>


using namespace std;

int main()
{
    cout << "Testing" << endl;
    Labyrinthe unLabyrinthe(true);

    char dir;
    while((dir = getch()) != 'q')
    {
        switch (dir)
        {
        
        case 'w':
            
            break;
        case 'a':

            break;
        case 's':
            
            break;
        case 'd':
            
            break;
        
        default:
            break;

            
        }
        
    }
    return 0;
}