#include "cpptest/struct/Color.h"

namespace cpptest {

    Color::Color(float r, float g, float b, float a) : red{r}, green{g}, blue{b}, alpha{a} {}

    Color::Color() : red{getRandom(0, 1)}, green{getRandom(0, 1)}, blue{getRandom(0, 1)}, alpha{1} {}

}// namespace cpptest
