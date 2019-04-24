#ifndef VECTOR2D_HH
#define VECTOR2D_HH

#include <cmath>
#include <iomanip>
#include <iostream>

template <typename T> class Vector2D {

  public:
    Vector2D() : px(0.0), py(0.0) {}

    Vector2D(T x, T y) : px(x), py(y) {}

    T x() const { return this->px; }

    T y() const { return this->py; }

    Vector2D<T> operator+(const Vector2D<T> v) const {
        return Vector2D(this->px + v.px, this->py + v.py);
    }

    Vector2D<T> operator-(const Vector2D<T> v) const {
        return Vector2D(this->px - v.px, this->py - v.py);
    }

    Vector2D<T> operator*(T f) const {
        return Vector2D(this->px * f, this->py * f);
    }

    Vector2D<T> operator/(T f) const {
        return Vector2D(this->px / f, this->py / f);
    }

    bool operator==(const Vector2D<T> v) const {
        return this->px == v.px && this->py == v.py;
    }

    bool operator!=(const Vector2D<T> v) const { return !(this == v); }

    Vector2D<T> &operator=(const Vector2D<T> v) {
        this->px = v.px;
        this->py = v.py;
        return *this;
    }

    Vector2D<T> &operator+=(const Vector2D<T> v) {
        this->px += v.px;
        this->py += v.py;
        return *this;
    }

    Vector2D<T> &operator-=(const Vector2D<T> v) {
        this->px -= v.px;
        this->py -= v.py;
        return *this;
    }

    Vector2D<T> &operator*=(T f) {
        this->px *= f;
        this->py *= f;
        return *this;
    }

    Vector2D<T> &operator/=(T f) {
        this->px /= f;
        this->py /= f;
        return *this;
    }

    double mod() const {
        return std::sqrt(this->px * this->px + this->py * this->py);
    }

    friend std::ostream &operator<<(std::ostream &s, const Vector2D<T> v) {
        s << std::setprecision(2) << "(" << v.px << ", " << v.py << ")";
        return s;
    }

  private:
    T px, py;
};

#endif // VECTOR2D_HH