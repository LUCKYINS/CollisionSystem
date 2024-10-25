#include <SDL2/SDL.h>
#include "../src/collision.hpp"
#include "../src/vec.hpp"

int size = 500;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Event e;
Vec2 mousepos;
Uint16 start;
Uint16 end;
float elapsedMS;
GridLayer grid;

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
    grid = GridLayer(size, size);
}
bool inRect(Vec2 origin){
    int w = 100, h=100;
    bool leftlimit = origin.getX()> mousepos.getX() - w/2;
    bool rightlimit = origin.getX()<mousepos.getX() + w/2;
    bool uplimit = origin.getY()> mousepos.getY() - h/2;
    bool downlimit = origin.getY()<mousepos.getY() + h/2;
    return leftlimit && rightlimit && uplimit && downlimit;
}
void rect(){
    for (Uint32 i= 0; i < grid.getDimension() ; ++i){
        if(inRect(grid.getCellsVector()[i].getOrigin())){
            grid.getCellsVector()[i].cellOn();
        }
    }
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
        }
    }
}

void Update(){
    grid.allCellOff();rect();
}

void Animation(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    //Draw
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 200);
    for (Cell i: grid.getCellsVector()){
        if (i.isOn()){
            SDL_RenderDrawPoint(renderer, i.getOrigin().getX(), i.getOrigin().getY());
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
        elapsedMS = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
        SDL_Delay(16.666f - elapsedMS);
    }
}

int main(){
    Init();
    Load();
    Loop();
}
