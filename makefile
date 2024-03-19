RPG:	RPG.cpp
	g++ RPG.cpp -c

Main:	Main.cpp
	g++ Main.cpp -c

clean:
	rm -f RPG.o Main.o main

run: RPG.o main.o
	g++ Main.o RPG.o -o main