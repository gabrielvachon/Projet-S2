Labyrinthe: main.o joueur.o labyrinthe.o tuile.o 
	g++ -o Labyrinthe main.cpp joueur.cpp labyrinthe.cpp tuile.cpp

main.o : main.cpp labyrinthe.h tuile.h joueur.h position.h p12_controller.h
	g++ -g -c main.cpp

labyrinthe.o: labyrinthe.cpp labyrinthe.h tuile.h joueur.h
	g++ -g -c labyrinthe.cpp

joueur.o: joueur.cpp joueur.h position.h labyrinthe.h
	g++ -g -c joueur.cpp

tuile.o: tuile.cpp tuile.h
	g++ -g -c tuile.cpp

p12_controller.o: p12_controller.cpp p12_controller.h

clean:
	del *.o