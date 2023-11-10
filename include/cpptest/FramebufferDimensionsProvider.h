#ifndef SQUARES_TEST_CPP_FRAMEBUFFERDIMENSIONSPROVIDER_H
#define SQUARES_TEST_CPP_FRAMEBUFFERDIMENSIONSPROVIDER_H

namespace cpptest {

    class FramebufferDimensionsProvider {
    public:
        [[nodiscard]] virtual float width() const = 0;
        [[nodiscard]] virtual float height() const = 0;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_FRAMEBUFFERDIMENSIONSPROVIDER_H
