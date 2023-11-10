#include "cpptest/shaders/ShaderProgram.h"

namespace cpptest {

    ShaderProgram::ShaderProgram(const std::string &shadersFolderPath) {
        int success;
        char infoLog[512];

        std::string vertexShaderSource = cpptest::readFile(shadersFolderPath + "/vshader.vert");
        const char *vShaderSourceSString = vertexShaderSource.c_str();
        unsigned int vertexShader;
        vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vShaderSourceSString, nullptr);
        glCompileShader(vertexShader);

        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
            std::cout << "Could not compile vertex shader, cause: " << infoLog << std::endl;
        }

        std::string fragmentShaderSource = cpptest::readFile(shadersFolderPath + "/fshader.frag");
        const char *fShaderSourceSString = fragmentShaderSource.c_str();
        unsigned int fragmentShader;
        fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fShaderSourceSString, nullptr);
        glCompileShader(fragmentShader);

        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
            std::cout << "Could not compile fragment shader, cause: " << infoLog << std::endl;
        }

        ID = glCreateProgram();
        glAttachShader(ID, vertexShader);
        glAttachShader(ID, fragmentShader);
        glLinkProgram(ID);

        glGetProgramiv(ID, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(ID, 512, nullptr, infoLog);
            std::cout << "Could not link shader program, cause: " << infoLog << std::endl;
        }

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void ShaderProgram::use() const {
        glUseProgram(ID);
    }

}// namespace cpptest
