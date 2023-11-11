#ifndef SQUARES_TEST_CPP_ENGINE_H
#define SQUARES_TEST_CPP_ENGINE_H

#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <iostream>
#include "cpptest/struct/Color.h"
#include "cpptest/struct/InputAction.h"
#include "DimensionsProvider.h"
#include <queue>
#include "cpptest/util/Coordinates.h"

#if defined(__APPLE__) && defined(__MACH__)
#define IS_MACOS true
#else
#define IS_MACOS false
#endif

namespace cpptest {

    class Engine : public DimensionsProvider {
    private:
        double lastPointerPosX = 0;
        double lastPointerPosY = 0;

        static std::queue<InputAction> *inputActionsQueue;
        static Engine *engineSingleton;

        std::string windowName;

        int initialWindowWidth;
        int initialWindowHeight;

        GLFWwindow *window = nullptr;
        static void framebufferSizeCallback(GLFWwindow *window, int width, int height);
        static void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods);
        static void mouseButtonCallback(GLFWwindow *window, int button, int action, int mods);
        static void cursorPosCallback(GLFWwindow *window, double xPos, double yPos);
        void processInputActionsQueue();
        void processMainLoopStep();

    protected:
        Color backgroundColor{BLACK};
        std::string shadersFolderPath;

        Engine(std::string name, float width, float height, std::string shadersFolder);
        virtual void init() = 0;
        virtual void update() = 0;
        virtual void redraw() = 0;
        virtual void onFramebufferResize(float width, float height) = 0;
        virtual void onPointerDown(float xPos, float yPos) = 0;
        virtual void onPointerMove(float prevX, float prevY, float xPos, float yPos) = 0;
        virtual void onPointerUp() = 0;
        virtual ~Engine() = default;

    public:
        void run();
        [[nodiscard]] glm::vec2 getWindowDimensions() const override;
        [[nodiscard]] glm::vec2 getFramebufferDimensions() const override;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_ENGINE_H
