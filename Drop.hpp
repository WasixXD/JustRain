#ifndef Drop_hpp
#define Drop_hpp


#include <SDL2/SDL.h>
#include <iostream>


int colors[7][3] = {
    {251, 73, 52},
    {184,187, 38},
    {250,189, 47},
    {131,165,152},
    {211,134,155},
    {142,192,124},
    {254,128,  2},

};




class Drop {
    public: 
        int x, y, yspeed, length;
        int *color = colors[(rand() % 7)];
        Drop(int x, int y, int yspeed, int length) {
            this->x = x;
            this->y = y;
            this->yspeed = yspeed;
            this->length = length;
        }

        void update(int canvasHeight, int canvasWidth) {
            this->y += this->yspeed;
            this->x -= 1;
            if(this->y > canvasHeight) {
                this->y = 0;

            } else if(this->x < 0) {
                this->x = canvasWidth;
            }
        }

        void draw(SDL_Renderer *renderer) {
            



            SDL_SetRenderDrawColor(renderer, this->color[0], this->color[1], this->color[2], 0);
            SDL_RenderDrawLine(renderer, this->x, this->y, this->x, this->y - this->length);
        }


        
};






#endif