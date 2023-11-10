#ifndef SQUARES_TEST_CPP_INPUTACTION_H
#define SQUARES_TEST_CPP_INPUTACTION_H

namespace cpptest {

    enum InputActionType {
        POINTER_UP,
        POINTER_DOWN,
        POINTER_MOVE,
        WINDOW_RESIZE
    };

    struct InputAction {
        InputActionType type;
        int x;
        int y;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_INPUTACTION_H
