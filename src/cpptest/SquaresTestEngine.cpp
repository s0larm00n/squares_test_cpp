#include "cpptest/SquaresTestEngine.h"

namespace cpptest {

    SquaresTestEngine::SquaresTestEngine(std::string name, float width, float height, std::string shadersFolder)
        : Engine{std::move(name), width, height, std::move(shadersFolder)} {}

    void SquaresTestEngine::init() {
        shaderProgram = new ShaderProgram{shadersFolderPath, this};
        squareManager = new SquareManager{shaderProgram};
    }

    void SquaresTestEngine::update() {}

    void SquaresTestEngine::redraw() {
        squareManager->draw();
    }

    void SquaresTestEngine::onFramebufferResize(float width, float height) {
        squareManager->ensureBorders();
    }

    void SquaresTestEngine::onPointerDown(float xPos, float yPos) {
        squareManager->onPointerDown(xPos, yPos);
    }

    void SquaresTestEngine::onPointerMove(float prevX, float prevY, float xPos, float yPos) {
        squareManager->onPointerMove(xPos - prevX, yPos - prevY);
    }

    void SquaresTestEngine::onPointerUp() {
        squareManager->onPointerUp();
    }

    SquaresTestEngine::~SquaresTestEngine() {
        delete shaderProgram;
        delete squareManager;
    }

}// namespace cpptest
