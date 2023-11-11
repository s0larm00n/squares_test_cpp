#include "cpptest/shaders/ShaderProgram.h"

namespace cpptest {

    ShaderProgram::ShaderProgram(const std::string &shadersFolderPath, const DimensionsProvider *dimensionsProvider)
        : canvasDimensionsProvider{dimensionsProvider} {
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

    void ShaderProgram::setColorAttribute(const Color &color) const {
        GLint uniformLocation = glGetUniformLocation(ID, "inputColor");
        glUniform4f(uniformLocation, color.red, color.green, color.blue, color.alpha);
    }

    void ShaderProgram::setTransformMatrix(const glm::mat4 &transform) const {
        GLint uniformLocation = glGetUniformLocation(ID, "transform");
        glUniformMatrix4fv(uniformLocation, 1, GL_FALSE, glm::value_ptr(transform));
    }

    void ShaderProgram::setPlain2DTransformMatrix(float x, float y, float width, float height, float zIndex) const {
        glm::vec2 framebufferSize = canvasDimensionsProvider->getFramebufferDimensions();
        float ndcX = (2.0f * x) / framebufferSize.x - 1.0f;
        float ndcY = 1.0f - (2.0f * y) / framebufferSize.y;
        float ndcWidth = width / framebufferSize.x;
        float ndcHeight = height / framebufferSize.y;
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, glm::vec3(ndcX, ndcY, zIndex));
        transform = glm::scale(transform, glm::vec3(ndcWidth, ndcHeight, 1.0f));
        setTransformMatrix(transform);
    }

}// namespace cpptest
