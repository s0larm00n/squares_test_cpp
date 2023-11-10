#ifndef SQUARES_TEST_CPP_SQUARESTESTENGINE_H
#define SQUARES_TEST_CPP_SQUARESTESTENGINE_H

#include "cpptest/Engine.h"
#include "cpptest/shaders/ShaderProgram.h"
#include "cpptest/models/BoxModel.h"
#include "cpptest/squares/SquareController.h"

namespace cpptest {

    class SquaresTestEngine : public Engine {
    private:
        cpptest::ShaderProgram *shaderProgram = nullptr;
        cpptest::BoxModel *boxModel = nullptr;

    protected:
        void init() override;
        void update() override;
        void redraw() override;
        void onWindowResize(int width, int height) override;
        void onPointerDown(double xPos, double yPos) override;
        void onPointerMove(double prevX, double prevY, double xPos, double yPos) override;
        void onPointerUp() override;

    public:
        SquaresTestEngine(std::string name, int width, int height, std::string shadersFolder);
        ~SquaresTestEngine() override;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SQUARESTESTENGINE_H
