#ifndef SPACESHIP_POINT_HPP
#define SPACESHIP_POINT_HPP

#include <cmath>
#include "util.hpp"

/**
 * A point in 2D space.
 */
class Point {
public:
    int x, y;

    /**
     * No argument constructor returns (0,0).
     */
    Point() {
        x = 0;
        y = 0;
    }

    /**
     * Creates a point with the given coordinates.
     * @param x: x coordinate
     * @param y: y coordinate
     */
    Point(const int x, const int y) {
        this->x = x;
        this->y = y;
    }

    Point(const float magnitude, const float direction) {
        x = math::x_from_polar(magnitude, direction);
        y = math::y_from_polar(magnitude, direction);
    }

    [[nodiscard]] float get_magnitude() const {
        return std::sqrt(x * x + y * y);
    }

    [[nodiscard]] float get_direction() const {
        auto theta = std::atan(y / (float) x);
        if (x >= 0) {
            return theta;
        } else {
            return theta + std::numbers::pi;
        }
    }

    void from_polar(const float magnitude, const float direction) {
        x = math::x_from_polar(magnitude, direction);
        y = math::y_from_polar(magnitude, direction);
    }


};

#endif //SPACESHIP_POINT_HPP
