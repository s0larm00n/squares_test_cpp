#include "cpptest/Engine.h"

namespace cpptest {

    std::queue<InputAction> *Engine::inputActionsQueue = new std::queue<InputAction>{};
    Engine *Engine::engineSingleton = nullptr;

    Engine::Engine(std::string name, float width, float height, std::string shadersFolder)
        : windowName{std::move(name)}, initialWindowWidth{(int) width}, initialWindowHeight{(int) height},
          shadersFolderPath{std::move(shadersFolder)} {
        engineSingleton = this;
    }

    void Engine::run() {
        glfwInit();
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        if (IS_MACOS) {
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
        }

        window = glfwCreateWindow(initialWindowWidth, initialWindowHeight, windowName.c_str(), nullptr, nullptr);
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

        int frameBufferWidth;
        int frameBufferHeight;
        glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
        glViewport(0, 0, frameBufferWidth, frameBufferHeight);

        glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);
        glfwSetKeyCallback(window, keyCallback);
        glfwSetMouseButtonCallback(window, mouseButtonCallback);
        glfwSetCursorPosCallback(window, cursorPosCallback);

        glEnable(GL_DEPTH_TEST);

        init();

        while (!glfwWindowShouldClose(window)) {
            processMainLoopStep();
        }

        glfwTerminate();
    }

    void Engine::processMainLoopStep() {
        processInputActionsQueue();
        update();
        glClearColor(backgroundColor.red, backgroundColor.green, backgroundColor.blue, backgroundColor.alpha);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        redraw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Engine::processInputActionsQueue() {
        std::queue<InputAction> snapshotQueue{*inputActionsQueue};
        while (!snapshotQueue.empty()) {
            InputAction action = snapshotQueue.front();
            glm::vec2 windowSize = getWindowDimensions();
            glm::vec2 framebufferSize = getFramebufferDimensions();

            switch (action.type) {
                case FRAMEBUFFER_RESIZE: {
                    onFramebufferResize(action.x, action.y);
                    break;
                }
                case POINTER_UP: {
                    onPointerUp();
                    break;
                }
                case POINTER_DOWN: {
                    onPointerDown(
                            convert(action.x, windowSize.x, framebufferSize.x),
                            convert(action.y, windowSize.y, framebufferSize.y)
                    );
                    break;
                }
                case POINTER_MOVE: {
                    onPointerMove(
                            convert(lastPointerPosX, windowSize.x, framebufferSize.x),
                            convert(lastPointerPosY, windowSize.y, framebufferSize.y),
                            convert(action.x, windowSize.x, framebufferSize.x),
                            convert(action.y, windowSize.y, framebufferSize.y)
                    );
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
        glViewport(0, 0, width, height);
        inputActionsQueue->push(InputAction{FRAMEBUFFER_RESIZE, (float) width, (float) height});
        // TODO this is a workaround (window resizing blocks main thread)
        engineSingleton->processMainLoopStep();
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
                    inputActionsQueue->push(InputAction{POINTER_DOWN, (float) xPos, (float) yPos});
                    break;
                }
                case GLFW_RELEASE: {
                    inputActionsQueue->push(InputAction{POINTER_UP, (float) xPos, (float) yPos});
                    break;
                }
                default: {
                    // Do nothing
                }
            }
        }
    }

    void Engine::cursorPosCallback(GLFWwindow *window, double xPos, double yPos) {
        inputActionsQueue->push(InputAction{POINTER_MOVE, (float) xPos, (float) yPos});
    }

    glm::vec2 Engine::getWindowDimensions() const {
        int width;
        int height;
        glfwGetWindowSize(window, &width, &height);
        return glm::vec2{width, height};
    }

    glm::vec2 Engine::getFramebufferDimensions() const {
        int width;
        int height;
        glfwGetFramebufferSize(window, &width, &height);
        return glm::vec2{width, height};
    }

}// namespace cpptest
