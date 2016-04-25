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

    fixed_point operator+() const;
    fixed_point operator-() const;
    fixed_point operator+(fixed_point rhs) const;
    fixed_point operator-(fixed_point rhs) const;
    fixed_point operator/(fixed_point rhs) const;

    fixed_point &operator+=(fixed_point rhs);
    fixed_point &operator-=(fixed_point rhs);

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


#endif //CPP_BHT_SOSE16_A02_FIXED_POINT_H
