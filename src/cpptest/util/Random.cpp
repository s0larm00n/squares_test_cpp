#include "cpptest/util/Random.h"

namespace cpptest {

    float getRandom(float from, float to) {
        static std::random_device rd;
        static std::mt19937 gen(rd());
        std::uniform_real_distribution<float> distribution(from, to);
        return distribution(gen);
    }

}// namespace cpptest
