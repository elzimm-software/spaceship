#ifndef SPACESHIP_CONTROLLABLE_BODY_HPP
#define SPACESHIP_CONTROLLABLE_BODY_HPP

#include "point.hpp"
#include "vector2.hpp"

class ControllableBody {
protected:
    Point pos;
    float rotation;
    float speed;

public:
    Vector2 velocity;

    ControllableBody(int x, int y, float rotation, float speed) {
        pos = Point(x, y);
        this->rotation = rotation;
        this->speed = speed;
        velocity = {0, 0};
    }

    ControllableBody(Point pos, float rotation, float speed) {
        this->pos = pos;
        this->rotation = rotation;
        this->speed = speed;
        velocity = {0, 0};
    }

    void move() {
        velocity = unit_vector(velocity);
        pos.x += (velocity[0] * speed);
        pos.y += (velocity[1] * speed);
    }
};

#endif //SPACESHIP_CONTROLLABLE_BODY_HPP
