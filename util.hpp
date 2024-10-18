#ifndef SPACESHIP_UTIL_HPP
#define SPACESHIP_UTIL_HPP

#include <cmath>
#include <numbers>

namespace constants {
    const auto HALF_PI = std::numbers::pi / 2;
}


float degree_to_radian(float theta) {
    return theta * std::numbers::pi / 180;
}

float radian_to_degree(float theta) {
    return theta * 180 / std::numbers::pi;
}

[[nodiscard]] int x_from_polar(const float magnitude, const float direction) {
    return magnitude * std::cos(direction);
}

[[nodiscard]] int y_from_polar(const float magnitude, const float direction) {
    return magnitude * std::sin(direction);
}

#endif //SPACESHIP_UTIL_HPP
