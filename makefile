Labyrinthe: main.o joueur.o labyrinthe.o tuile.o 
	g++ -o main.cpp joueur.cpp labyrinthe.cpp tuile.cpp
main.o : main.cpp labyrinthe.h joueur.h
	g++ main.cpp -g -c
labyrinthe.o: labyrinthe.cpp labyrinthe.h tuile.h
	g++ labyrinthe.cpp -g -c
joueur.o: joueur.cpp joueur.h
	g++ joueur.cpp -g -c
tuile.o: tuile.cpp tuile.h
	g++ tuile.cpp -g -c
