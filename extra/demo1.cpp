#include <iostream>
#include <SDL2/SDL.h>
#include "../src/collision.hpp"
#include "../src/vec.hpp"

int size = 500;
SDL_Window *window;
SDL_Renderer * renderer;
SDL_Event e;

bool Init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("%s", SDL_GetError());
        return false;
    }
    window = SDL_CreateWindow("Demo1", 0, 500, size, size, SDL_WINDOW_SHOWN);
    if(!window){
        printf("%s", SDL_GetError());
        return false;
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer){
        printf("%s", SDL_GetError());
        return false;
    }
    return true;
}

void destory(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    exit(1);
}

void event(){
    while (SDL_PollEvent(&e) !=0 ){
        switch (e.type) {
            case SDL_QUIT:
                destory();
        }
    }
}



void loop(){
    while (1) {
        event();
    }
}

void load(){}
void animation(){}

int main(){
    if (!Init()){return 1;};
    loop();
    return 0;
}
