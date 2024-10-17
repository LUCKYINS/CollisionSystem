#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
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

    //rec
    Rectangle r(800, 100);
    Shape2DCollision dr(r, Vec2(0, 400));
    SDL_Rect rec;
    rec.x = dr.getCentre().getX();
    rec.y = dr.getCentre().getY();
    rec.w = dr.getWidth();
    rec.h = dr.getHeight();

    //MRUA
    double a = 0.1;
    double v = 0;
    double y = 0;

    //Square
    Rectangle s(100,100);
    Shape2DCollision ds(s,Vec2(0, 0));
    SDL_Rect square;
    square.x = ds.getCentre().getX();
    square.y = ds.getCentre().getY();
    square.w = ds.getWidth();
    square.h = ds.getHeight();

    //collision
    CollisionObjectContainer container;
    container.addCollisionObject(dr);
    container.addCollisionObject(ds);

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
        ds.changeCentre(Vec2(0,1));
        square.y = ds.getCentre().getY();

        //
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &square);
        SDL_RenderFillRect(renderer, &rec);

        SDL_RenderPresent(renderer);

        v += a;
        y += v + (1/2) * a;

        container.checkCollision();

        Uint64 end = SDL_GetPerformanceCounter();
        float elapseMS = (end-start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(16.666f -elapseMS);
    }
    return 0;
}
