#ifndef TXT_CONVERTER_HPP
#define TXT_CONVERTER_HPP

#include <string>
#include <vector>

namespace TxtConverter {
/**
 *  @brief convert a txt file into a vector
 *  @param path the path of the txt file
 *  @return a 2D vector that stored integer
 */
static std::vector<std::vector<int>> Convert(const std::string &path);
}; // namespace TxtConverter

#endif // TXT_CONVERTER_HPP
