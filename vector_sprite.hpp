#ifndef VECTOR_SPRITE_hpp_
#define VECTOR_SPRITE_hpp_

#include <SDL2/SDL.h>
#include <cmath>
#include "point.hpp"
#include "util.hpp"

/**
 * Sprite constructed from a list of vertexes.
 */
class VectorSprite {
private:
    Point pos;
    float rotation;
    float scale;
    const Point* vertexes;
    int vertex_count;

public:
    VectorSprite(const int x, const int y, const float rotation, const float scale, const Point* vertexes, const int vertex_count) {
        pos = Point(x,y);
        this->rotation = rotation;
        this->scale = scale;
        this->vertexes = vertexes;
        this->vertex_count = vertex_count;
    }

    VectorSprite(const Point pos, const float rotation, const float scale, const Point* vertexes, const int vertex_count) {
        this->pos = pos;
        this->rotation = rotation;
        this->scale = scale;
        this->vertexes = vertexes;
        this->vertex_count = vertex_count;
    }

    void render(SDL_Renderer* renderer) {
        for (int i = 0; i < vertex_count; i++) {
            auto v1 = vertexes[i];
            auto v2 = vertexes[(i+1) % vertex_count];
            auto r1 = v1.get_direction() + rotation;
            auto r2 = v2.get_direction() + rotation;
            auto m1 = v1.get_magnitude() * scale;
            auto m2 = v2.get_magnitude() * scale;

            SDL_RenderDrawLine(renderer, pos.x + x_from_polar(m1, r1), pos.y - y_from_polar(m1,r1), pos.x + x_from_polar(m2, r2), pos.y - y_from_polar(m2, r2));
        }
    }
};

#endif