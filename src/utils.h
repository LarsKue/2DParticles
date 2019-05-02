//
// Created by Lars on 02/05/2019.
//

#ifndef INC_2DPARTICLES_UTILS_H
#define INC_2DPARTICLES_UTILS_H

#include <cmath>
#include <limits>

template<typename T, typename std::enable_if<!std::numeric_limits<T>::is_integer, bool>::type = true>
bool almost_equal(T x, T y, int ulp) {
    // the machine epsilon has to be scaled to the magnitude of the values used
    // and multiplied by the desired precision in ULPs (units in the last place)
    return std::abs(x-y) <= std::numeric_limits<T>::epsilon() * std::abs(x+y) * ulp
           // unless the result is subnormal
           || std::abs(x-y) < std::numeric_limits<T>::min();
}

#endif //INC_2DPARTICLES_UTILS_H
