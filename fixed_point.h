//
// Created by Timo on 18.04.2016.
//

#ifndef CPP_BHT_SOSE16_A02_FIXED_POINT_H
#define CPP_BHT_SOSE16_A02_FIXED_POINT_H


#include <cstdint>

template <int8_t Decimal, int8_t Fraction>
class fixed_point {
public:
    fixed_point(float x);

    explicit operator int() const;
    explicit operator float() const;

    template <int8_t DecimalF, int8_t FractionF>
    friend fixed_point<DecimalF, FractionF> abs(fixed_point<DecimalF, FractionF> fixedPoint);

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

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> sin(fixed_point<Decimal, Fraction> x);

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> cos(fixed_point<Decimal, Fraction> x);

#endif //CPP_BHT_SOSE16_A02_FIXED_POINT_H
