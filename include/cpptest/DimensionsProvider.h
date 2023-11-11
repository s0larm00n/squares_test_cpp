#ifndef SQUARES_TEST_CPP_DIMENSIONSPROVIDER_H
#define SQUARES_TEST_CPP_DIMENSIONSPROVIDER_H

#include "glm/glm.hpp"

namespace cpptest {

    class DimensionsProvider {
    public:
        [[nodiscard]] virtual glm::vec2 getWindowDimensions() const = 0;
        [[nodiscard]] virtual glm::vec2 getFramebufferDimensions() const = 0;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_DIMENSIONSPROVIDER_H
