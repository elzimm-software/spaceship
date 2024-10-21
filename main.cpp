#include <iostream>
#include <SDL2/SDL.h>
#include "vector_sprite.hpp"
#include "point.hpp"
#include "util.hpp"

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define PLAYER big_ship

int main(int argc, char **argv) {
    if (SDL_Init(SDL_INIT_EVERYTHING) > 0) {
        std::cout << "Error initializing SDL" << std::endl;
        return 1;
    }
    SDL_Window *window = SDL_CreateWindow("Spaceship", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                                          WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);
    Point small_ship_vertexes[3] = {Point(15, 0), Point(-10, 10), Point(-10, -10)};
    VectorSprite small_ship = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0, 1, 10, small_ship_vertexes, 3};
    Point big_ship_vertexes[13] = {{30,  0},
                                   {18,  12},
                                   {18,  6},
                                   {3,   6},
                                   {-12, 30},
                                   {-24, 30},
                                   {-21, 6},
                                   {-21, -6},
                                   {-24, -30},
                                   {-12, -30},
                                   {3,   -6},
                                   {18,  -6},
                                   {18,  -12}};
    VectorSprite big_ship = {WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0, 1, 10, big_ship_vertexes, 13};
    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_KEYDOWN:
                    if (event.key.repeat == 0) {
                        switch (event.key.keysym.sym) {
                            case SDLK_a:
                                std::cout << "a down" << std::endl;
                                PLAYER.velocity[0] -= 1;
                                break;
                            case SDLK_d:
                                std::cout << "d down" << std::endl;
                                PLAYER.velocity[0] += 1;
                                break;
                            case SDLK_w:
                                std::cout << "w down" << std::endl;
                                PLAYER.velocity[1] -= 1;
                                break;
                            case SDLK_s:
                                std::cout << "s down" << std::endl;
                                PLAYER.velocity[1] += 1;
                                break;
                            case SDLK_ESCAPE:
                                running = false;
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                case SDL_KEYUP:
                    if (event.key.repeat == 0) {
                        switch (event.key.keysym.sym) {
                            case SDLK_a:
                                std::cout << "a up" << std::endl;
                                if (PLAYER.velocity[0] < 0) {
                                    PLAYER.velocity[0] = 0;
                                }
                                break;
                            case SDLK_d:
                                std::cout << "d up" << std::endl;
                                if (PLAYER.velocity[0] > 0) {
                                    PLAYER.velocity[0] = 0;
                                }
                                break;
                            case SDLK_w:
                                std::cout << "w up" << std::endl;
                                if (PLAYER.velocity[1] > 0) {
                                    PLAYER.velocity[1] = 0;
                                }
                                break;
                            case SDLK_s:
                                std::cout << "s up" << std::endl;
                                if (PLAYER.velocity[1] < 0) {
                                    PLAYER.velocity[1] = 0;
                                }
                                break;
                            default:
                                break;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        PLAYER.move();
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        big_ship.render(renderer);
        SDL_RenderPresent(renderer);
        SDL_Delay(100);
    }
    return 0;
}
