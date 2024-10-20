GXX = g++
CFlages = -Wall -Wextra -Werror=all
SDLFlages= -lSDL2

all: complie link

link: test.o
	$(GXX) test.o $(CFlages) $(SDLFlages) -o test.exe
complie: test.cpp
	$(GXX) $(CFlages) -c test.cpp

noF:
	g++ main.cpp -o main $(SDLFlages)
rmall:
	rm *.o *.exe
