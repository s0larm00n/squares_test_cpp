#ifndef SQUARES_TEST_CPP_SQUARECONTROLLER_H
#define SQUARES_TEST_CPP_SQUARECONTROLLER_H

#include "cpptest/models/BoxModel.h"
#include "cpptest/shaders/ShaderProgram.h"
#include "cpptest/struct/Color.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

namespace cpptest {

    class SquareController {
    private:
        ShaderProgram *shaderProgram;
        BoxModel *boxModel;
        glm::vec3 location{0, 0, 0};
        float size = 0;
        bool isHighlighted = false;

    public:
        Color color;
        SquareController(ShaderProgram *program, BoxModel *model, float x, float y, float sideSize);
        void draw();
        [[nodiscard]] bool containsPoint(float x, float y) const;
        void moveBy(float deltaX, float deltaY);
        void ensureBorders(float framebufferWidth, float framebufferHeight);
        void switchHighlight(bool value);
        void setZIndex(float index);
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SQUARECONTROLLER_H
