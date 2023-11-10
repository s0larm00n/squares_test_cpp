#ifndef SQUARES_TEST_CPP_SHADERPROGRAM_H
#define SQUARES_TEST_CPP_SHADERPROGRAM_H

#include "glad/glad.h"
#include <string>
#include "cpptest/util/IOHelper.h"

namespace cpptest {

    class ShaderProgram {
    private:
        unsigned int ID = 0;

    public:
        explicit ShaderProgram(const std::string &shadersFolderPath);
        void use() const;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SHADERPROGRAM_H
