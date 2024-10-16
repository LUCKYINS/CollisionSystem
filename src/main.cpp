#include <SDL2/SDL.h>
#include <unordered_set>
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
    SDL_Window *window = SDL_CreateWindow("Bouncing Ball", 300, 300, w, h,SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    //rec
    SDL_Rect rec;
    rec.x = 0;
    rec.y = 400;
    rec.w = 800;
    rec.h = 50;

    //MRUA
    double a = 0.1;
    double v = 0;
    double y = 0;

    //Square
    SDL_Rect square;
    square.x = 0;
    square.y = y;
    square.w = 50;
    square.h = 50;

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
        square.y = y;

        //
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &square);
        SDL_RenderFillRect(renderer, &rec);

        SDL_RenderPresent(renderer);
        v = v + a;
        y = y + v + (1/2) * a;
        Uint64 end = SDL_GetPerformanceCounter();
        float elapseMS = (end-start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(16.666f -elapseMS);
    }
    return 0;
}
