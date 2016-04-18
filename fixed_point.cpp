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