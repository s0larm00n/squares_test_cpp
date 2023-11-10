#ifndef SQUARES_TEST_CPP_COLOR_H
#define SQUARES_TEST_CPP_COLOR_H

namespace cpptest {

    struct Color {
        float red;
        float green;
        float blue;
        float alpha;

        Color(float r, float g, float b, float a);
    };

    inline Color WHITE{1, 1, 1, 1};
    inline Color BLACK{0, 0, 0, 1};
    inline Color GREEN{0, 1, 0, 1};

}// namespace cpptest

#endif//SQUARES_TEST_CPP_COLOR_H
