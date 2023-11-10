#include "cpptest/models/BoxModel.h"

namespace cpptest {

    std::vector<float> BoxModel::boxVertices =
            {0.5f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f, -0.5f, 0.5f, 0.0f};

    std::vector<unsigned int> BoxModel::boxIndices = {0, 1, 3, 1, 2, 3};

    BoxModel::BoxModel() : Model{boxVertices, boxIndices} {}

}// namespace cpptest
