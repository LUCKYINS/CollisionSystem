#include <iostream>
#include <SDL2/SDL.h>
#include "../src/collision.hpp"
#include "../src/vec.hpp"

int size = 500;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;
Vec2 mousepos;
Uint64 start;
Uint64 end;
float elapsedMS;
SDL_Rect rect;




void Init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("%s", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("Demo1", 0, 200, size, size, SDL_WINDOW_SHOWN);
    if(!window){
        printf("%s", SDL_GetError());
        exit(1);
    }
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer){
        printf("%s", SDL_GetError());
        exit(1);
    }
}
void Load(){
    rect.x = 100;
    rect.y = 100;
    rect.h = 100;
    rect.w = 100;
}

void Destroy(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    exit(0);
}

void Event(){
    while (SDL_PollEvent(&e) !=0 ){
        mousepos = Vec2(e.motion.x, e.motion.y);
        switch (e.type) {
            case SDL_QUIT:
                Destroy();
            break;
        }
    }
}
void Update(){
    // Follow mouse
    rect.x = mousepos.getX() - rect.w/2.0;
    rect.y = mousepos.getY() - rect.h/2.0;
}

void Animation(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    //Draw
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
    SDL_RenderFillRect(renderer, &rect);
    //Draw
    SDL_RenderPresent(renderer);
}

void Loop(){
    while (1) {
        start = SDL_GetPerformanceCounter();
        Event();
        Update();
        Animation();
        end = SDL_GetPerformanceCounter();
        //Delta Time
        elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(floor(16.666f - elapsedMS));
    }
}

int main(){
    Init();
    Load();
    Loop();
}
