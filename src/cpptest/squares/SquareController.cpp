#include "cpptest/squares/SquareController.h"

namespace cpptest {

    SquareController::SquareController(ShaderProgram *program, BoxModel *model)
        : shaderProgram{program}, boxModel{model} {}

    void SquareController::draw() {
        shaderProgram->use();
        shaderProgram->setColorAttribute(color);

        int x = 500;
        int y = 100;
        int width = 50, height = 50;

        shaderProgram->setPlain2DTransformMatrix(x, y, width, height);

        // proj view model local
        boxModel->draw();
    }

}// namespace cpptest
