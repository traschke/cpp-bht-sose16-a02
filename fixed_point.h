//
// Created by Timo on 18.04.2016.
//

#ifndef CPP_BHT_SOSE16_A02_FIXED_POINT_H
#define CPP_BHT_SOSE16_A02_FIXED_POINT_H


#include <cstdint>

class fixed_point {
public:
    fixed_point(float x);

    explicit operator int() const;
    explicit operator float() const;

    friend fixed_point abs(fixed_point fixedPoint);

    fixed_point operator+() const;
    fixed_point operator-() const;
    fixed_point operator+(fixed_point rhs) const;
    fixed_point operator-(fixed_point rhs) const;
    fixed_point operator*(fixed_point rhs) const;
    fixed_point operator/(fixed_point rhs) const;

    fixed_point &operator+=(fixed_point rhs);
    fixed_point &operator-=(fixed_point rhs);
    fixed_point &operator*=(fixed_point rhs);
    fixed_point &operator/=(fixed_point rhs);

    bool operator==(fixed_point rhs) const;
    bool operator!=(fixed_point rhs) const;
    bool operator<(fixed_point rhs) const;
    bool operator>(fixed_point rhs) const;
    bool operator<=(fixed_point rhs) const;
    bool operator>=(fixed_point rhs) const;
    fixed_point& operator++();
    fixed_point operator++(int);
    fixed_point& operator--();
    fixed_point operator--(int);

private:
    std::int32_t q;
};

fixed_point sin(fixed_point x);
fixed_point cos(fixed_point x);

#endif //CPP_BHT_SOSE16_A02_FIXED_POINT_H
