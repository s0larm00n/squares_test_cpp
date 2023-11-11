#include "cpptest/squares/SquareController.h"

namespace cpptest {

    SquareController::SquareController(ShaderProgram *program, BoxModel *model, float x, float y, float sideSize)
        : shaderProgram{program}, boxModel{model}, color{} {
        location.x = x;
        location.y = y;
        size = sideSize;
    }

    void SquareController::draw() {
        shaderProgram->use();

        if (isHighlighted) {
            static float minFloatStep = std::numeric_limits<float>::epsilon();
            shaderProgram->setColorAttribute(WHITE);
            shaderProgram
                    ->setPlain2DTransformMatrix(location.x, location.y, size + 3, size + 3, location.z + minFloatStep);
            boxModel->draw();
        }
        shaderProgram->setColorAttribute(color);
        shaderProgram->setPlain2DTransformMatrix(
                location.x,
                location.y,
                size - (isHighlighted ? 2 : 0),
                size - (isHighlighted ? 2 : 0),
                location.z
        );
        boxModel->draw();
    }

    bool SquareController::containsPoint(float x, float y) const {
        return x >= location.x - size / 2 && x <= location.x + size / 2 && y >= location.y - size / 2 &&
               y <= location.y + size / 2;
    }

    void SquareController::moveBy(float deltaX, float deltaY) {
        location.x += deltaX;
        location.y += deltaY;
    }

    void SquareController::ensureBorders(float framebufferWidth, float framebufferHeight) {
        if (location.x - size / 2 < 0) {
            location.x = size / 2;
        }
        if (location.x + size / 2 > framebufferWidth) {
            location.x = framebufferWidth - size / 2;
        }
        if (location.y - size / 2 < 0) {
            location.y = size / 2;
        }
        if (location.y + size / 2 > framebufferHeight) {
            location.y = framebufferHeight - size / 2;
        }
    }

    void SquareController::setZIndex(float index) {
        location.z = index;
    }

    void SquareController::switchHighlight(bool value) {
        isHighlighted = value;
    }

}// namespace cpptest
