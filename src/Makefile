GXX = g++
CFlages = -Wall -Wextra -Werror=all
SDLFlages= -lSDL2

all: complie link

link:
	$(GXX) main.o $(CFlages) $(SDLFlages) -o main
complie:
	$(GXX) $(CFlages) -c main.cpp

rmall:
	rm main.o main
