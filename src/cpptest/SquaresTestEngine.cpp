#include "cpptest/SquaresTestEngine.h"

namespace cpptest {

    SquaresTestEngine::SquaresTestEngine(std::string name, int width, int height, std::string shadersFolder)
        : Engine{std::move(name), width, height, std::move(shadersFolder)} {}

    void SquaresTestEngine::init() {
        shaderProgram = new ShaderProgram{shadersFolderPath, this};
        boxModel = new BoxModel{};
    }

    void SquaresTestEngine::update() {}

    void SquaresTestEngine::redraw() {
        shaderProgram->use();
        SquareController squareController{shaderProgram, boxModel};
        squareController.draw();
    }

    void SquaresTestEngine::onFramebufferResize(int width, int height) {
        std::cout << "resize: " << width << ", " << height << std::endl;
    }

    void SquaresTestEngine::onPointerDown(double xPos, double yPos) {
        std::cout << "down: " << xPos << ", " << yPos << std::endl;
    }

    void SquaresTestEngine::onPointerMove(double prevX, double prevY, double xPos, double yPos) {
        std::cout << "move: " << prevX << ", " << prevY << "; "<< xPos << ", " << yPos << std::endl;
    }

    void SquaresTestEngine::onPointerUp() {
        std::cout << "up";
    }

    SquaresTestEngine::~SquaresTestEngine() {
        delete boxModel;
        delete shaderProgram;
    }

}// namespace cpptest
