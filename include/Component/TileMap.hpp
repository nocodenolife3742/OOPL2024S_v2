#ifndef TILE_MAP_HPP
#define TILE_MAP_HPP

#include "Util/GameObject.hpp"
#include "pch.hpp"
#include <string>
#include <vector>

namespace TileMap {
const glm::vec2 SCALE = {3, 3};
const glm::vec2 TILE_SIZE = {32, 32};

/**
 *  @brief convert a txt file into a 2D vector
 *  @param path the path of the txt file
 *  @return a 2D vector that stored integer
 */
std::vector<std::vector<int>> ConvertToTiles(const std::string &path);

/**
 * @brief get the position of the tile
 * @param x the x position of the tile
 * @param y the y position of the tile
 * @return the position of the tile
 */
glm::vec2 GetTilePosition(const int &x, const int &y);

class Map {
public:
    /**
     * @brief Construct a new Map object
     * @param stageName the name of the stage, this will be used to load the txt
     * file
     */
    explicit Map(std::string stageName);

    /**
     * @brief Get the objects in the map
     * @return the objects in the map
     */
    [[nodiscard]] std::vector<std::shared_ptr<Util::GameObject>>
    GetObjects() const;

    Map() = default;

    ~Map() = default;

private:
    std::string m_StageName;
    std::vector<std::shared_ptr<Util::GameObject>> m_Objects;
};
}; // namespace TileMap

#endif // TILE_MAP_HPP
