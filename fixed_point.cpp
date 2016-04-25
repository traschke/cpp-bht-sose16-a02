//
// Created by Timo on 18.04.2016.
//

#include <cmath>
#include "fixed_point.h"

fixed_point::fixed_point(float x) {
    q = x * std::pow(2, 16);
}

fixed_point::operator int() const {
    return q / std::pow(2, 16);
}

fixed_point::operator float() const {
    return q / std::pow(2, 16);
}

fixed_point fixed_point::operator+() const {
    fixed_point temp(*this);
    return temp;
}

fixed_point fixed_point::operator-() const {
    fixed_point temp(*this);
    temp.q = -temp.q;
    return temp;
}

fixed_point fixed_point::operator+(fixed_point rhs) const {
    fixed_point temp(*this);
    temp.q += rhs.q;
    return temp;
}

bool fixed_point::operator==(fixed_point rhs) const {
    return q == rhs.q;
}

bool fixed_point::operator!=(fixed_point rhs) const {
    return q != rhs.q;
}

bool fixed_point::operator<(fixed_point rhs) const {
    return q < rhs.q;
}

bool fixed_point::operator>(fixed_point rhs) const {
    return q > rhs.q;
}

bool fixed_point::operator<=(fixed_point rhs) const {
    return q <= rhs.q;
}

bool fixed_point::operator>=(fixed_point rhs) const {
    return q >= rhs.q;
}

fixed_point& fixed_point::operator++() {
    q += std::pow(2, 16);
    return *this;
}

fixed_point fixed_point::operator++(int) {
    fixed_point temp = *this;
    q += std::pow(2, 16);
    return temp;
}

fixed_point& fixed_point::operator--() {
    q -= std::pow(2, 16);
    return *this;
}

fixed_point fixed_point::operator--(int) {
    fixed_point temp = *this;
    q -= std::pow(2, 16);
    return temp;
}

fixed_point fixed_point::operator-(fixed_point rhs) const {
    fixed_point temp = *this;
    temp.q -= rhs.q;
    return temp;
}

fixed_point fixed_point::operator*(fixed_point rhs) const {
    fixed_point lhs = *this;
    lhs.q = ((int64_t)lhs.q * (int64_t)rhs.q) >> 16;
    return lhs;
}

fixed_point fixed_point::operator/(fixed_point rhs) const {
    fixed_point tempFixed(*this);

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

fixed_point &fixed_point::operator+=(fixed_point rhs) {
    q += rhs.q;
    return *this;
}

fixed_point &fixed_point::operator-=(fixed_point rhs) {
    q -= rhs.q;
    return *this;
}

fixed_point &fixed_point::operator/=(fixed_point rhs) {
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

fixed_point &fixed_point::operator*=(fixed_point rhs) {
    q = ((int64_t)q * (int64_t)rhs.q) >> 16;
    return *this;
}



