#ifndef SQUARES_TEST_CPP_MODEL_H
#define SQUARES_TEST_CPP_MODEL_H

#include "glad/glad.h"
#include <vector>

namespace cpptest {

    // Simple 1-attribute (vec3) model
    class Model {
    private:
        unsigned int VBO{};
        unsigned int VAO{};
        unsigned int EBO{};

    protected:
        float *vertices = nullptr;
        int verticesCount = 0;
        unsigned int *indices = nullptr;
        int indicesCount = 0;

    public:
        explicit Model(const std::vector<float> &modelVertices, const std::vector<unsigned int> &modelIndices);
        void use() const;
        void draw() const;
        virtual ~Model();
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_MODEL_H
