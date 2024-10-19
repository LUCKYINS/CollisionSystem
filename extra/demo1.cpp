#include <iostream>
#include <SDL2/SDL.h>
#include "../src/collision.hpp"
#include "../src/vec.hpp"

int size = 500;
SDL_Window *window;
SDL_Renderer * renderer;
SDL_Event e;
Uint64 start;
Uint64 end;
float elapsedMS;

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

void Destroy(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    exit(0);
}

void Event(){
    while (SDL_PollEvent(&e) !=0 ){
        switch (e.type) {
            case SDL_QUIT:
                Destroy();
        }
    }
}



void Loop(){
    while (1) {
        start = SDL_GetPerformanceCounter();
        Event();
        //

        //
        end = SDL_GetPerformanceCounter();
        //Delta Time
        elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(floor(16.666f - elapsedMS));
    }
}


void Animation(){}

int main(){
    if (!Init()){return 1;};
    Loop();
}
