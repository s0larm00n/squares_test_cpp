#ifndef SQUARES_TEST_CPP_BOXMODEL_H
#define SQUARES_TEST_CPP_BOXMODEL_H

#include "Model.h"

namespace cpptest {

    class BoxModel : public Model {
    private:

    public:
        static std::vector<float> boxVertices;
        static std::vector<unsigned int> boxIndices;
        BoxModel();
        ~BoxModel() override = default;
    };

}// namespace cpptest

#endif//SQUARES_TEST_CPP_BOXMODEL_H
