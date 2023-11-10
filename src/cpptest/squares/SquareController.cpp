#include "cpptest/squares/SquareController.h"

namespace cpptest {


    SquareController::SquareController(ShaderProgram *program, BoxModel *model)
        : shaderProgram{program}, boxModel{model} {}

    void SquareController::draw() {
        shaderProgram->use();
        shaderProgram->setColorAttribute(color);
        boxModel->draw();
    }

}// namespace cpptest
