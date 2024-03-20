#include "Component/TileMap.hpp"
#include "Component/ImageObject.hpp"
#include "Util/LoadTextFile.hpp"
#include <sstream>
#include <utility>

std::vector<std::vector<int>> TileMap::ConvertToTiles(const std::string &path) {
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

glm::vec2 TileMap::GetTilePosition(const int &x, const int &y) {
    double positionX = 0.5 * SCALE.y * TILE_SIZE.y * y;
    double positionY = -0.5 * SCALE.x * TILE_SIZE.x * x;
    return {positionX, positionY};
}

TileMap::Map::Map(std::string stageName)
    : m_StageName(std::move(stageName)) {
    // load tiles
    std::vector<std::vector<int>> tiles =
        ConvertToTiles(RESOURCE_DIR "/Map/BackGround/" + m_StageName + ".txt");

    // set objects
    for (std::size_t x = 0; x < tiles.size(); x++) {
        for (std::size_t y = 0; y < tiles[x].size(); y++) {
            // skip empty
            if (tiles[x][y] == 0)
                continue;

            // set object
            std::string path = RESOURCE_DIR "/Picture/Tiles/" + m_StageName +
                               "/BackGround/" + std::to_string(tiles[x][y]) +
                               ".png";
            auto object = std::make_shared<ImageObject>(path);
            object->SetPosition(
                GetTilePosition(static_cast<int>(x), static_cast<int>(y)));
            object->SetScale(SCALE);
            m_Objects.push_back(object);
        }
    }
}

std::vector<std::shared_ptr<Util::GameObject>>
TileMap::Map::GetObjects() const {
    return m_Objects;
}
