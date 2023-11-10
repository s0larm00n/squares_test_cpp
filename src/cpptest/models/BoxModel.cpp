#include "cpptest/models/BoxModel.h"

namespace cpptest {

    std::vector<float> BoxModel::boxVertices =
            {1.f, 1.f, 0.f, 1.f, -1.f, 0.f, -1.f, -1.f, 0.f, -1.f, 1.f, 0.f};

    std::vector<unsigned int> BoxModel::boxIndices = {0, 1, 3, 1, 2, 3};

    BoxModel::BoxModel() : Model{boxVertices, boxIndices} {}

}// namespace cpptest
