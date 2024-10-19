GXX = g++
CFlages = -Wall -Wextra -Werror=all
SDLFlages= -lSDL2

all: complie link

link: main.o
	$(GXX) main.o $(CFlages) $(SDLFlages) -o main.exe
complie: main.cpp
	$(GXX) $(CFlages) -c main.cpp

noF:
	g++ main.cpp -o main $(SDLFlages)
rmall:
	rm *.o *.exe
