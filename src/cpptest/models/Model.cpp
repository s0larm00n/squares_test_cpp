#include "cpptest/models/Model.h"

namespace cpptest {

    Model::Model(const std::vector<float> &modelVertices, const std::vector<unsigned int> &modelIndices) {
        vertices = new float[modelVertices.size()];
        verticesCount = modelVertices.size();
        for (int i = 0; i < verticesCount; i++) {
            vertices[i] = modelVertices[i];
        }
        indices = new unsigned int[modelIndices.size()];
        indicesCount = modelIndices.size();
        for (int i = 0; i < indicesCount; i++) {
            indices[i] = modelIndices[i];
        }

        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);

        glBindVertexArray(VAO);
        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * verticesCount, vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * indicesCount, indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        glBindBuffer(GL_ARRAY_BUFFER, 0);
        glBindVertexArray(0);
    }

    void Model::use() const {
        glBindVertexArray(VAO);
    }

    void Model::draw() const {
        use();
        glDrawElements(GL_TRIANGLES, indicesCount, GL_UNSIGNED_INT, 0);
    }

    Model::~Model() {
        delete[] vertices;
        delete[] indices;
    }

}// namespace cpptest
