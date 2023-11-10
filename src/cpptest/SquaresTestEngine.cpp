#include "cpptest/SquaresTestEngine.h"

namespace cpptest {

    SquaresTestEngine::SquaresTestEngine(std::string name, int width, int height, std::string shadersFolder)
        : Engine{std::move(name), width, height, std::move(shadersFolder)} {}

    void SquaresTestEngine::init() {
        shaderProgram = new ShaderProgram{shadersFolderPath};
        boxModel = new BoxModel{};
    }

    void SquaresTestEngine::update() {}

    void SquaresTestEngine::redraw() {
        shaderProgram->use();
        boxModel->draw();
    }

    void SquaresTestEngine::onWindowResize(int width, int height) {
        std::cout << "resize";
    }

    void SquaresTestEngine::onPointerDown(double xPos, double yPos) {
        std::cout << "down";
    }

    void SquaresTestEngine::onPointerMove(double prevX, double prevY, double xPos, double yPos) {
        std::cout << "move";
    }

    void SquaresTestEngine::onPointerUp() {
        std::cout << "up";
    }

    SquaresTestEngine::~SquaresTestEngine() {
        delete boxModel;
        delete shaderProgram;
    }

}// namespace cpptest
