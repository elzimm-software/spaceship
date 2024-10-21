#ifndef SPACESHIP_VECTOR2_HPP
#define SPACESHIP_VECTOR2_HPP

#include <cmath>
#include <iostream>

class Vector2 {
private:
    float e[2];

public:
    Vector2() : e(0,0) {}

    Vector2(float x, float y) : e{x,y} {}

    [[nodiscard]] float x() const {
        return e[0];
    }

    [[nodiscard]] float y() const {
        return e[1];
    }

    Vector2 operator-() const {
        return {-e[0], -e[1]};
    }

    float& operator[] (int i) {return e[i];}

    Vector2& operator+= (const Vector2& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        return *this;
    }

    Vector2& operator*= (float t) {
        e[0] *= t;
        e[1] *= t;
    }

    Vector2& operator/=(float t) {
        return *this *= 1/t;
    }

    [[nodiscard]] float length() const {
        return std::sqrt(length_squared());
    }

    [[nodiscard]] float length_squared() const {
        return e[0]*e[0]+e[1]*e[1];
    }
};

inline std::ostream& operator<< (std::ostream& out, const Vector2& v) {
    return out << v.x() << " " << v.y();
}

inline Vector2 operator+(const Vector2& u, const Vector2& v) {
    return {u.x() + v.x(), u.y() + v.y()};
}

inline Vector2 operator- (const Vector2& u, const Vector2& v) {
    return {u.x()-v.x(), u.y()-v.y()};
}

inline Vector2 operator* (const Vector2& u, const Vector2& v) {
    return {u.x()*v.x(), u.y()+v.y()};
}

inline Vector2 operator* (float t, const Vector2& v) {
    return {t*v.x(), t*v.y()};
}

inline Vector2 operator* (const Vector2& v, float t) {
    return t*v;
}

inline Vector2 operator/(const Vector2& v, float t) {
    return (1/t) * v;
}

inline Vector2 unit_vector(const Vector2& v) {
    return v / v.length();
}

#endif //SPACESHIP_VECTOR2_HPP
