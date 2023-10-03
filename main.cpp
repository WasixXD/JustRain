#include <iostream>
#include <SDL2/SDL.h>
#include "Drop.hpp"
#include <vector>
#include <cstdlib>


const int WIDTH = 1920, HEIGHT = 1080;



void clear_screen(SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 40, 40, 40, 0);
    SDL_RenderClear(renderer);
}



int main( int argc, char *argv[]) {
    
    SDL_Init( SDL_INIT_EVERYTHING );
    SDL_Window *window = SDL_CreateWindow("SDL2 Window",
                                          SDL_WINDOWPOS_UNDEFINED,
                                          SDL_WINDOWPOS_UNDEFINED,
                                          WIDTH, HEIGHT,
                                          SDL_WINDOW_SHOWN);

    if(NULL == window) {
        std::cout << "Could not create window: " << SDL_GetError();
        return 1;   
    }

    SDL_Event windowEvent;
    SDL_Renderer *window_renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    
    
    SDL_SetRenderDrawColor(window_renderer, 40, 40, 40, 0);


    std::vector<Drop> cloud;
    for(int i = 0; i < 450; i++) {
        int x = (rand() % WIDTH);
        int y = (rand() % HEIGHT);
        int yspeed = (rand() % 7) + 3.5f;
        int length = (rand() % 7) + 10;
        Drop drop(x, y, yspeed, length);
        cloud.push_back(drop);
        
    }
    
   

    //gameLoop
    while(1) {

        while(SDL_PollEvent(&windowEvent)) {
            if(windowEvent.type == SDL_QUIT){
                SDL_Quit();
            }

        }

        
        for(int i = 0; i < cloud.size(); i++) {
            cloud[i].update(HEIGHT, WIDTH);
            cloud[i].draw(window_renderer);
        }
        SDL_SetRenderDrawColor(window_renderer, 0, 255, 253, 255);
        
        SDL_Delay(1000/30);
       
        SDL_RenderPresent(window_renderer);

        clear_screen(window_renderer);

    }




    

    SDL_DestroyWindow(window);
    SDL_Quit();




  
   
    return 0;
}