GXX = g++
CFlages = -Wall -Wextra -Werror=all
SFMLFlages= -lsfml-system -lsfml-audio -lsfml-window -lsfml-graphics

all: complie link

link:
	$(GXX) main.o $(CFlages) $(SFMLFlages) -o main
complie:
	$(GXX) $(CFlages) -c main.cpp 

rmall:
	rm main.o main