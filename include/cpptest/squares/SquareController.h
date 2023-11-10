#ifndef SQUARES_TEST_CPP_SQUARECONTROLLER_H
#define SQUARES_TEST_CPP_SQUARECONTROLLER_H

#include "cpptest/models/BoxModel.h"
#include "cpptest/shaders/ShaderProgram.h"
#include "cpptest/struct/Color.h"

namespace cpptest {

    class SquareController {
    private:
        ShaderProgram *shaderProgram;
        BoxModel *boxModel;

    public:
        Color color{GREEN};
        SquareController(ShaderProgram *program, BoxModel *model);
        void draw();
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SQUARECONTROLLER_H
