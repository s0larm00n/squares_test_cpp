#ifndef SQUARES_TEST_CPP_ENGINE_H
#define SQUARES_TEST_CPP_ENGINE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "cpptest/struct/Color.h"
#include "cpptest/struct/InputAction.h"
#include <queue>

#if defined(__APPLE__) && defined(__MACH__)
#define IS_MACOS true
#else
#define IS_MACOS false
#endif

namespace cpptest {

    class Engine {
    private:
        double lastPointerPosX = 0;
        double lastPointerPosY = 0;

        static std::queue<InputAction> *inputActionsQueue;
        std::string windowName;
        int windowWidth;
        int windowHeight;
        static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
        static void cursorPosCallback(GLFWwindow *window, double xPos, double yPos);
        void processInputActionsQueue();

    protected:
        Color backgroundColor{0, 0, 0, 1};
        std::string shadersFolderPath;

        Engine(std::string name, int width, int height, std::string shadersFolder);
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void redraw() = 0;
        virtual void onWindowResize(int width, int height) = 0;
        virtual void onPointerDown(double xPos, double yPos) = 0;
        virtual void onPointerMove(double prevX, double prevY, double xPos, double yPos) = 0;
        virtual void onPointerUp() = 0;
        virtual ~Engine() = default;

    public:
        void run();
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_ENGINE_H
