#include <SDL2/SDL_events.h>
#include <SDL2/SDL_mouse.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <SDL2/SDL_timer.h>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>
#include <iostream>
#include <SDL2/SDL.h>
#include <vector>
#include "../src/collision.hpp"
#include "../src/vec.hpp"

#define SIZE 400
#define SCREENSIZE 400
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;
Vec2 mousepos;
Uint64 start;
Uint64 end;
float elapsedMS;
SDL_Rect rect;
bool spawnOn = false;


struct RectB{
    void setSandColor(int x){
        switch (x) {
            case 0:
                sandColor = Vec3(104,152,128);
                break;
            case 1:
                sandColor =Vec3(104,167,128);
                break;
            case 2:
                sandColor = Vec3(104,173,128);
                break;
        }

    }
    SDL_Rect rect;
    Vec3 sandColor;
    bool on = false;
};

std::vector<RectB> sandVector = {};

bool inRect(RectB &obj){
    return mousepos.getX() <= obj.rect.x + obj.rect.w && mousepos.getX() > obj.rect.x && mousepos.getY() <= obj.rect.y + obj.rect.h && mousepos.getY() > obj.rect.y;
}

void grid(){
    for (int i = 0; i< SIZE*SIZE; ++i){
        SDL_Rect r = rect;
        r.x+=(int)i%SIZE * r.w;
        r.y+=(int)i/SIZE * r.h;
        RectB b;
        b.rect = r;
        int x = rand()%3;
        b.setSandColor(x);
        sandVector.push_back(b);
    }
}

void Spawn(){
    for (int i = 0; i< SIZE*SIZE; ++i){
        if(inRect(sandVector[i])){
            for(int j = 0; j < 15; j++){
                sandVector[i].on = true;
                sandVector[i+SIZE*j].on = true;
                sandVector[i-SIZE*j].on = true;
                for(int k = 0; k < 15; k++){
                sandVector[i+SIZE*j+k].on = true;
                sandVector[i-SIZE*j-k].on = true;
                sandVector[i+SIZE*j-k].on = true;
                sandVector[i-SIZE*j+k].on = true;
                }
            }
        }
    }
}

void Init(){
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0){
        printf("%s", SDL_GetError());
        exit(1);
    }
    window = SDL_CreateWindow("Demo2", 200, 200, SCREENSIZE, SCREENSIZE, SDL_WINDOW_SHOWN);
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
    srand((unsigned) time(NULL));
    rect.x = 0;
    rect.y = 0;
    rect.h = 1;
    rect.w = 1;

    grid();
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
            case SDL_MOUSEBUTTONDOWN:
                switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                        spawnOn = true;
                        break;
                }
                break;
            case SDL_MOUSEBUTTONUP:
                switch (e.button.button) {
                    case SDL_BUTTON_LEFT:
                        spawnOn = false;
                        break;
                }
                break;
        }
    }
}
void Update(){
    if(spawnOn)Spawn();
    // Mouse
    rect.x = (int)mousepos.getX()-rect.w/2;
    rect.y = (int)mousepos.getY()-rect.h/2;
    //
    for (int i=SIZE*SIZE; i >0; --i) {
        if (sandVector[i].on && !sandVector[i+SIZE].on && i+SIZE<SIZE*SIZE) {
            sandVector[i].on = false;
            sandVector[i+SIZE].on = true;
        }
        if (sandVector[i].on && sandVector[i+SIZE].on && !sandVector[i+SIZE+1].on && i+SIZE<SIZE*SIZE) {
            sandVector[i].on = false;
            sandVector[i+SIZE+1].on = true;
        }
        if (sandVector[i].on && sandVector[i+SIZE].on && !sandVector[i+SIZE-1].on && i+SIZE<SIZE*SIZE) {
            sandVector[i].on = false;
            sandVector[i+SIZE-1].on = true;
        }
    }
}

void Animation(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    //Draw
    for (RectB i: sandVector){
        if(i.on){
            SDL_SetRenderDrawColor(renderer, i.sandColor.getX(), i.sandColor.getY(),i.sandColor.getZ(), 100);
            SDL_RenderFillRect(renderer, &i.rect);
        }

    }
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
        elapsedMS = (float)(end - start) / SDL_GetPerformanceFrequency() * 1000.0f;
    }
}

int main(){
    Init();
    Load();
    Loop();
}
