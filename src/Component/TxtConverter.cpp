#include "Component/TxtConverter.hpp"
#include "Util/LoadTextFile.hpp"
#include "Util/Logger.hpp"
#include <sstream>

std::vector<std::vector<int>> TxtConverter::Convert(const std::string &path) {
    std::vector<std::vector<int>> result;

    // load text file into stream
    std::string text = Util::LoadTextFile(path);
    std::istringstream stream(text);
    std::string line;

    // convert stream into lines
    while (std::getline(stream, line)) {
        std::vector<int> row_result;
        std::istringstream line_stream(line);
        std::string token;

        // convert line into tokens
        while (std::getline(line_stream, token, ' '))
            row_result.push_back(std::stoi(token));
        result.push_back(row_result);
    }

    // return result
    return result;
}
