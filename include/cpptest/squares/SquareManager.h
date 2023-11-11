#ifndef SQUARES_TEST_CPP_SQUAREMANAGER_H
#define SQUARES_TEST_CPP_SQUAREMANAGER_H

#include "cpptest//squares/SquareController.h"
#include <algorithm>
#include <vector>

namespace cpptest {

    class SquareManager {
    private:
        ShaderProgram *shaderProgram;
        BoxModel *boxModel;
        const DimensionsProvider *framebufferDimensionsProvider;

        std::vector<SquareController *> squares{};
        int detectCollisionWith(float x, float y);
        void refreshZIndexes();

        SquareController *focused = nullptr;

    public:
        SquareManager(ShaderProgram *program);
        SquareController *getTopSquare();
        void draw();
        SquareController *getSquareByLocation(float x, float y);
        SquareController *addSquare(float posX, float posY);
        void ensureBorders();
        void onPointerDown(float x, float y);
        void onPointerUp();
        void onPointerMove(float deltaX, float deltaY);
        ~SquareManager();
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SQUAREMANAGER_H
