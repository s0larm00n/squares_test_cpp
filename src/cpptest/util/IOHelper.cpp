#include "cpptest/util/IOHelper.h"

namespace cpptest {

    std::string readFile(const std::string &filename) {
        std::ifstream file(filename);
        if (!file.is_open()) {
            std::cerr << "Failed to open file: " << filename << std::endl;
            return "";
        }
        std::ostringstream contentStream;
        std::string line;
        while (std::getline(file, line)) {
            contentStream << line << '\n';
        }
        file.close();
        return std::move(contentStream.str());
    }

}// namespace cpptest
