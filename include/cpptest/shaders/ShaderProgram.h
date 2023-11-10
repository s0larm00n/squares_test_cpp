#ifndef SQUARES_TEST_CPP_SHADERPROGRAM_H
#define SQUARES_TEST_CPP_SHADERPROGRAM_H

#include "glad/glad.h"
#include <string>
#include "cpptest/util/IOHelper.h"
#include "cpptest/struct/Color.h"

namespace cpptest {

    class ShaderProgram {
    private:
        unsigned int ID = 0;

    public:
        explicit ShaderProgram(const std::string &shadersFolderPath);
        void use() const;
        void setColorAttribute(const Color &color) const;
        void setAttribute(const std::string *name);
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SHADERPROGRAM_H
