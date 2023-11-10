#include "cpptest/SquaresTestEngine.h"

int main(int argc, char *argv[]) {
    std::string shadersFolderPath = "/shaders";
    if (argc >= 2) {
        shadersFolderPath = argv[1];
    }

    cpptest::SquaresTestEngine engine{"Squares test", 800, 600, shadersFolderPath};
    engine.run();
}
