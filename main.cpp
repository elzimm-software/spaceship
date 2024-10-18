#include <iostream>
#include <SDL2/SDL.h>
#include "vector_sprite.hpp"
#include "point.hpp"
#include "util.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

int main(int argc, char** argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "Error initializing SDL" << std::endl;
        return 1;
    }
    SDL_Window* window = SDL_CreateWindow("Spaceship", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
    Point ship_vertexes[3] = {Point(15,0), Point(-10,10), Point(-10,-10)};
    VectorSprite ship = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0, 1, ship_vertexes, 3};
    while (true) {
        SDL_SetRenderDrawColor(renderer, 255,255,255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0,0,0,255);
        ship.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    return 0;
}
