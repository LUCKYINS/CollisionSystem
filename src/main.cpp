#include <SDL2/SDL.h>
#include <SDL2/SDL_rect.h>
#include <SDL2/SDL_render.h>
#include <cinttypes>
#include <climits>
#include <cmath>
#include <cstdio>
#include "collision.hpp"
#include "vec.hpp"

int w = 800;
int h = 500;


void motion(){// TODO for object in motion
}
void animation(){// TODO when frame changes
}

int main(){
    //init
    SDL_Init(SDL_INIT_EVERYTHING);
    //window
    SDL_Window *window = SDL_CreateWindow("CollisionSystem", 300, 300, w, h,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //Square
    int xy = 1000000;
    int xy2 = pow(xy, 1.0/2.0);
    std::vector<SDL_Rect> recVec;
    for (int i; i < xy; i++){
        Rectangle s(2,2);
        Shape2DCollision ds(s,Vec2(i%xy2, i/xy2));
        SDL_Rect square;
        square.x = ds.getCentre().getX();
        square.y = ds.getCentre().getY();
        square.w = ds.getWidth();
        square.h = ds.getLength();
        recVec.push_back(square);
    }

    // event
    SDL_Event e;
    while(1){
        Uint64 start = SDL_GetPerformanceCounter();
        while (SDL_PollEvent(&e) != 0 ){
            switch (e.type) {
                case SDL_QUIT:
                    return 1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        //Draw
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        for (SDL_Rect i:recVec){
            SDL_RenderFillRect(renderer, &i);
        }

        //Deaw
        SDL_RenderPresent(renderer);
        system("read -p '' var");
        break;
        Uint64 end = SDL_GetPerformanceCounter();
        float elapseMS = (end-start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(16.666f -elapseMS);
    }
    return 0;
}
