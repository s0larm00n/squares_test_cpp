#ifndef SQUARES_TEST_CPP_SHADERPROGRAM_H
#define SQUARES_TEST_CPP_SHADERPROGRAM_H

#include "glad/glad.h"
#include <string>
#include "cpptest/util/IOHelper.h"
#include "cpptest/struct/Color.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "cpptest/DimensionsProvider.h"

namespace cpptest {

    class ShaderProgram {
    private:
        unsigned int ID = 0;

    public:
        const DimensionsProvider *canvasDimensionsProvider;

        explicit ShaderProgram(const std::string &shadersFolderPath, const DimensionsProvider *dimensionsProvider);
        void use() const;
        void setColorAttribute(const Color &color) const;
        void setTransformMatrix(const glm::mat4 &transform) const;
        void setPlain2DTransformMatrix(float x, float y, float width, float height, float zIndex) const;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_SHADERPROGRAM_H
