#ifndef SQUARES_TEST_CPP_SHADERPROGRAM_H
#define SQUARES_TEST_CPP_SHADERPROGRAM_H

#include "glad/glad.h"
#include <string>
#include "cpptest/util/IOHelper.h"
#include "cpptest/struct/Color.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "cpptest/FramebufferDimensionsProvider.h"

namespace cpptest {

    class ShaderProgram {
    private:
        unsigned int ID = 0;
        const FramebufferDimensionsProvider *viewportDimensionsProvider;
    public:
        explicit ShaderProgram(const std::string &shadersFolderPath, const FramebufferDimensionsProvider *dimensionsProvider);
        void use() const;
        void setColorAttribute(const Color &color) const;
        void setTransformMatrix(const glm::mat4 &transform) const;
        void setPlain2DTransformMatrix(float x, float y, float width, float height) const;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SHADERPROGRAM_H
