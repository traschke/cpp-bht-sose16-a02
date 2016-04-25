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

fixed_point fixed_point::operator-() const {
    fixed_point temp(*this);
    temp.q = -temp.q;
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