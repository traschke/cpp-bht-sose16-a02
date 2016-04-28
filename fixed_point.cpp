//
// Created by Timo on 18.04.2016.
//

#include <cmath>
#include "fixed_point.h"

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction>::fixed_point(float x) {
    //q = x * std::pow(2, 16);
    q = x * std::pow(2, Fraction);
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction>::operator int() const {
    return q / std::pow(2, Fraction);
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction>::operator float() const {
    return q / std::pow(2, Fraction);
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> abs(fixed_point<Decimal, Fraction> fixedPoint) {
    if (fixedPoint >= 0) {
        return fixedPoint;
    } else {
        return -fixedPoint;
    }
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator+() const {
    fixed_point temp(*this);
    return temp;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator-() const {
    fixed_point temp(*this);
    temp.q = -temp.q;
    return temp;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator+(fixed_point<Decimal, Fraction> rhs) const {
    fixed_point<Decimal, Fraction> temp(*this);
    temp.q += rhs.q;
    return temp;
}

template <int8_t Decimal, int8_t Fraction>
bool fixed_point<Decimal, Fraction>::operator==(fixed_point<Decimal, Fraction> rhs) const {
    return q == rhs.q;
}

template <int8_t Decimal, int8_t Fraction>
bool fixed_point<Decimal, Fraction>::operator!=(fixed_point<Decimal, Fraction> rhs) const {
    return q != rhs.q;
}

template <int8_t Decimal, int8_t Fraction>
bool fixed_point<Decimal, Fraction>::operator<(fixed_point<Decimal, Fraction> rhs) const {
    return q < rhs.q;
}

template <int8_t Decimal, int8_t Fraction>
bool fixed_point<Decimal, Fraction>::operator>(fixed_point<Decimal, Fraction> rhs) const {
    return q > rhs.q;
}

template <int8_t Decimal, int8_t Fraction>
bool fixed_point<Decimal, Fraction>::operator<=(fixed_point<Decimal, Fraction> rhs) const {
    return q <= rhs.q;
}

template <int8_t Decimal, int8_t Fraction>
bool fixed_point<Decimal, Fraction>::operator>=(fixed_point<Decimal, Fraction> rhs) const {
    return q >= rhs.q;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction>& fixed_point<Decimal, Fraction>::operator++() {
    q += std::pow(2, 16);
    return *this;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator++(int) {
    fixed_point<Decimal, Fraction> temp = *this;
    q += std::pow(2, 16);
    return temp;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction>& fixed_point<Decimal, Fraction>::operator--() {
    q -= std::pow(2, 16);
    return *this;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator--(int) {
    fixed_point<Decimal, Fraction> temp = *this;
    q -= std::pow(2, 16);
    return temp;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator-(fixed_point<Decimal, Fraction> rhs) const {
    fixed_point<Decimal, Fraction> temp = *this;
    temp.q -= rhs.q;
    return temp;
}

// TODO Values of type 'int64_t' may not fit into the receiver type 'int32_t'
template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator*(fixed_point<Decimal, Fraction> rhs) const {
    fixed_point<Decimal, Fraction> lhs = *this;
    lhs.q = ((int64_t)lhs.q * (int64_t)rhs.q) >> 16;
    return lhs;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> fixed_point<Decimal, Fraction>::operator/(fixed_point<Decimal, Fraction> rhs) const {
    fixed_point<Decimal, Fraction> tempFixed(*this);

    int32_t result;
    int64_t temp;

    temp = (int64_t) q << 16;

    if ((temp >= 0 && rhs.q >= 0) || (temp < 0 && rhs.q < 0)) {
        temp += rhs.q / 2;
    } else {
        temp -= rhs.q / 2;
    }

    result = (int32_t)(temp / rhs.q);

    tempFixed.q = result;

    return tempFixed;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> &fixed_point<Decimal, Fraction>::operator+=(fixed_point<Decimal, Fraction> rhs) {
    q += rhs.q;
    return *this;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> &fixed_point<Decimal, Fraction>::operator-=(fixed_point<Decimal, Fraction> rhs) {
    q -= rhs.q;
    return *this;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> &fixed_point<Decimal, Fraction>::operator/=(fixed_point<Decimal, Fraction> rhs) {
    int32_t result;
    int64_t temp;

    temp = (int64_t) q << 16;

    if ((temp >= 0 && rhs.q >= 0) || (temp < 0 && rhs.q < 0)) {
        temp += rhs.q / 2;
    } else {
        temp -= rhs.q / 2;
    }

    result = (int32_t)(temp / rhs.q);

    q = result;

    return *this;
}

// TODO Values of type 'int64_t' may not fit into the receiver type 'int32_t'
template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> &fixed_point<Decimal, Fraction>::operator*=(fixed_point<Decimal, Fraction> rhs) {
    q = ((int64_t)q * (int64_t)rhs.q) >> 16;
    return *this;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> sin(fixed_point<Decimal, Fraction> x) {
    return x - (x*x*x)/6 + (x*x*x*x*x)/120 - (x*x*x*x*x*x*x)/5040;
}

template <int8_t Decimal, int8_t Fraction>
fixed_point<Decimal, Fraction> cos(fixed_point<Decimal, Fraction> x) {
    return fixed_point<Decimal, Fraction>(1.f) - (x*x)/2 + (x*x*x*x)/24 - (x*x*x*x*x*x*x)/720;
}

// TODO Find a better solution to avoid this silly workaround!
// Workaround to avoid linking failures. See http://stackoverflow.com/a/8752879
template class fixed_point<16, 16>;