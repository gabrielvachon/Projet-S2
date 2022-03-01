Labyrinthe: main.o joueur.o labyrinthe.o tuile.o 
	g++ -o Labyrinthe main.cpp joueur.cpp labyrinthe.cpp tuile.cpp

main.o : main.cpp labyrinthe.h tuile.h joueur.h position.h
	g++ -g -c main.cpp

labyrinthe.o: labyrinthe.cpp labyrinthe.h tuile.h position.h
	g++ -g -c labyrinthe.cpp

joueur.o: joueur.cpp joueur.h position.h
	g++ -g -c joueur.cpp

tuile.o: tuile.cpp tuile.h
	g++ -g -c tuile.cpp

clean:
	del *.o