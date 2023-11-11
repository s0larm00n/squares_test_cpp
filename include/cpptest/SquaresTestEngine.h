#ifndef SQUARES_TEST_CPP_SQUARESTESTENGINE_H
#define SQUARES_TEST_CPP_SQUARESTESTENGINE_H

#include "cpptest/Engine.h"
#include "cpptest/shaders/ShaderProgram.h"
#include "cpptest/models/BoxModel.h"
#include "cpptest/squares/SquareController.h"
#include "cpptest/squares/SquareManager.h"

namespace cpptest {

    class SquaresTestEngine : public Engine {
    private:
        SquareManager *squareManager = nullptr;
        cpptest::ShaderProgram *shaderProgram = nullptr;

    protected:
        void init() override;
        void update() override;
        void redraw() override;
        void onFramebufferResize(float width, float height) override;
        void onPointerDown(float xPos, float yPos) override;
        void onPointerMove(float prevX, float prevY, float xPos, float yPos) override;
        void onPointerUp() override;

    public:
        SquaresTestEngine(std::string name, float width, float height, std::string shadersFolder);
        ~SquaresTestEngine() override;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SQUARESTESTENGINE_H
