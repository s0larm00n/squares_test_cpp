#include "cpptest/squares/SquareManager.h"

namespace cpptest {

    SquareManager::SquareManager(ShaderProgram *program)
        : shaderProgram{program}, boxModel{new BoxModel{}} {}

    SquareController *SquareManager::getTopSquare() {
        if (squares.empty()) {
            return nullptr;
        }
        return squares[squares.size() - 1];
    }

    void SquareManager::draw() {
        for (const auto &item: squares) {
            item->draw();
        }
    }

    int SquareManager::detectCollisionWith(float x, float y) {
        for (int i = squares.size() - 1; i >= 0; i--) {
            SquareController *square = squares[i];
            if (square->containsPoint(x, y)) {
                return i;
            }
        }
        return -1;
    }

    SquareController *SquareManager::getSquareByLocation(float x, float y) {
        int collisionIndex = detectCollisionWith(x, y);

        if (collisionIndex < 0) {
            return nullptr;
        }

        if (getTopSquare() != nullptr) {
            getTopSquare()->switchHighlight(false);
        }
        auto rotationIterator = squares.begin() + collisionIndex;
        std::rotate(rotationIterator, rotationIterator + 1, squares.end());
        refreshZIndexes();
        if (getTopSquare() != nullptr) {
            getTopSquare()->switchHighlight(true);
        }
        return getTopSquare();
    }

    SquareManager::~SquareManager() {
        for (SquareController *square: squares) {
            delete square;
        }
        delete boxModel;
    }

    SquareController *SquareManager::addSquare(float posX, float posY) {
        glm::vec2 framebufferSize = shaderProgram->canvasDimensionsProvider->getFramebufferDimensions();
        float size = std::min(framebufferSize.x, framebufferSize.y) / 10.f;
        SquareController *newSquare = new SquareController{shaderProgram, boxModel, (float) posX, (float) posY, size};
        newSquare->ensureBorders(framebufferSize.x, framebufferSize.y);
        if (getTopSquare() != nullptr) {
            getTopSquare()->switchHighlight(false);
        }
        squares.push_back(newSquare);
        getTopSquare()->switchHighlight(true);
        refreshZIndexes();
        return newSquare;
    }
    void SquareManager::refreshZIndexes() {
        // normalized Z-indexes based on squares amount
        float step = 1.f / squares.size();
        float nextIndex = 0;
        for (int i = 0; i < squares.size(); i++) {
            SquareController *square = squares[i];
            square->setZIndex(nextIndex);
            nextIndex -= step;
        }
    }

    void SquareManager::ensureBorders() {
        glm::vec2 framebufferSize = shaderProgram->canvasDimensionsProvider->getFramebufferDimensions();
        for (SquareController *square: squares) {
            square->ensureBorders(framebufferSize.x, framebufferSize.y);
        }
    }

    void SquareManager::onPointerDown(float x, float y) {
        focused = getSquareByLocation(x, y);
        if (focused == nullptr) {
            focused = addSquare(x, y);
        }
    }

    void SquareManager::onPointerUp() {
        focused = nullptr;
    }

    void SquareManager::onPointerMove(float deltaX, float deltaY) {
        if (focused != nullptr) {
            glm::vec2 framebufferSize = shaderProgram->canvasDimensionsProvider->getFramebufferDimensions();
            focused->moveBy(deltaX, deltaY);
            focused->ensureBorders(framebufferSize.x, framebufferSize.y);
        }
    }

}// namespace cpptest
