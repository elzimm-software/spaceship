#ifndef SPACESHIP_CONTROLLABLE_BODY_HPP
#define SPACESHIP_CONTROLLABLE_BODY_HPP

#include "point.hpp"
#include "vector2.hpp"

class ControllableBody {
protected:
    Point pos;
    float rotation;
    Vector2 velocity;

public:
    ControllableBody(int x, int y, float rotation) {
        pos = Point(x,y);
        this->rotation = rotation;
        velocity = {0,0};
    }

    ControllableBody(Point pos, float rotation) {
        this->pos = pos;
        this->rotation = rotation;
        velocity = {0,0};
    }
};

#endif //SPACESHIP_CONTROLLABLE_BODY_HPP
