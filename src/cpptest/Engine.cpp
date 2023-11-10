#include "cpptest/Engine.h"

namespace cpptest {

    std::queue<InputAction> *Engine::inputActionsQueue = new std::queue<InputAction>{};

    Engine::Engine(std::string name, int width, int height, std::string shadersFolder)
        : windowName{std::move(name)}, windowWidth{width}, windowHeight{height},
          shadersFolderPath{std::move(shadersFolder)} {}

    void Engine::run() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        if (IS_MACOS) {
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        }

        GLFWwindow *window = glfwCreateWindow(windowWidth, windowHeight, windowName.c_str(), nullptr, nullptr);
        if (window == nullptr) {
            std::cout << "Failed to create GLFW window" << std::endl;
            glfwTerminate();
            exit(-1);
        }
        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
            std::cout << "Failed to initialize GLAD" << std::endl;
            exit(-1);
        }

        int frameBufferWidth, frameBufferHeight;
        glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
        glViewport(0, 0, frameBufferWidth, frameBufferHeight);

        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
        glfwSetKeyCallback(window, keyCallback);
        glfwSetMouseButtonCallback(window, mouseButtonCallback);
        glfwSetCursorPosCallback(window, cursorPosCallback);

        init();

        while (!glfwWindowShouldClose(window)) {
            processInputActionsQueue();
            update();
            glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.alpha);
            glClear(GL_COLOR_BUFFER_BIT);
            redraw();
            glfwSwapBuffers(window);
            glfwPollEvents();
        }

        glfwTerminate();
    }

    void Engine::processInputActionsQueue() {
        std::queue<InputAction> snapshotQueue{*inputActionsQueue};
        while (!snapshotQueue.empty()) {
            InputAction action = snapshotQueue.front();
            switch (action.type) {
                case WINDOW_RESIZE: {
                    windowWidth = action.x;
                    windowHeight = action.y;
                    onWindowResize(action.x, action.y);
                    break;
                }
                case POINTER_UP: {
                    onPointerUp();
                    break;
                }
                case POINTER_DOWN: {
                    onPointerDown(action.x, action.y);
                    break;
                }
                case POINTER_MOVE: {
                    onPointerMove(lastPointerPosX, lastPointerPosY, action.x, action.y);
                    lastPointerPosX = action.x;
                    lastPointerPosY = action.y;
                    break;
                }
            }
            inputActionsQueue->pop();
            snapshotQueue.pop();
        }
    }

    void Engine::framebufferSizeCallback(GLFWwindow *window, int width, int height) {
        int frameBufferWidth, frameBufferHeight;
        glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
        glViewport(0, 0, width, height);
        inputActionsQueue->push(InputAction{WINDOW_RESIZE, width, height});
    }

    void Engine::keyCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
        if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
        }
    }

    void Engine::mouseButtonCallback(GLFWwindow *window, int button, int action, int mods) {
        if (button == GLFW_MOUSE_BUTTON_LEFT) {
            double xPos, yPos;
            glfwGetCursorPos(window, &xPos, &yPos);
            switch (action) {
                case GLFW_PRESS: {
                    inputActionsQueue->push(InputAction{POINTER_DOWN, (int) xPos, (int) yPos});
                    break;
                }
                case GLFW_RELEASE: {
                    inputActionsQueue->push(InputAction{POINTER_UP, (int) xPos, (int) yPos});
                    break;
                }
                default: {
                    // Do nothing
                }
            }
        }
    }

    void Engine::cursorPosCallback(GLFWwindow *window, double xPos, double yPos) {
        inputActionsQueue->push(InputAction{POINTER_MOVE, (int) xPos, (int) yPos});
    }

}// namespace cpptest
