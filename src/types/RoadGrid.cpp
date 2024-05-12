//
// Created by gawei on 11/05/2024.
//

#include <optional>
#include <iostream>
#include <set>
#include "../constants/Directions.h"
#include "../../include/types/RoadGrid.h"
#include "../exceptions/OutOfBoundsException.h"
#include "../exceptions/InvalidNonEmptyAssumption.h"
#include "../utils/EnumRange.h"
#include "../utils/SetUtils.h"

using namespace std::ranges::views;
namespace types {
    RoadGrid::RoadGrid(int height, int width) : gridHeight(height), gridWidth(width) {
        this->tiles = new std::optional<RoadTile> *[height];
        for (int i = 0; i < height; i++) {
            this->tiles[i] = new std::optional<RoadTile>[width];
            for (int j = 0; j < width; j++) {
                this->tiles[i][j] = std::nullopt;
            }
        }
    }

    RoadGrid::~RoadGrid() {
        for (int i = 0; i < this->gridHeight; i++) {
            delete[] this->tiles[i];
        }
        delete[] this->tiles;
    }

    RoadGrid::ConnectionType RoadGrid::accessibiltyFromDirection(Coord position, DirectionEnum incomingDir) {
        if (!this->IsInBounds(position)) {
            return RoadGrid::ConnectionType::ACCESSIBLE; // Allow roads to connect to edge of the map
        }
        const std::optional<const RoadTile> &tile = GetTile(position);
        if (!tile.has_value()) {
            return RoadGrid::ConnectionType::ACCESSIBLE;
        }

        if (utils::sets::Contains(tile.value().element->connections, Constants::OppositeDirections.at(incomingDir))) {
            return RoadGrid::ConnectionType::CONNECTION;
        } else {
            return RoadGrid::ConnectionType::NONE;
        }
    }

    bool RoadGrid::IsInBounds(Coord position) const {
        return position.x >= 0 && position.x < this->gridWidth && position.y >= 0 && position.y < this->gridHeight;
    }

    std::optional<RoadTile> &RoadGrid::GetTile(Coord position) {
        if (!this->IsInBounds(position)) {
            throw exceptions::OutOfBoundsException("Position out of bounds");
        }
        return this->tiles[position.y][position.x];
    }


    RoadTile &RoadGrid::GetTileNotNull(Coord position) {
        std::optional<RoadTile> &optTile = this->GetTile(position);
        if (!optTile.has_value()) {
            throw exceptions::InvalidNonEmptyAssumption("Tile is empty but it was accessed as a non empty tile");
        }
        return optTile.value();

    }

    void RoadGrid::SetTile(Coord position, RoadElement const *element) {
        if (!this->IsInBounds(position)) {
            throw std::invalid_argument("Position out of bounds");
        }
        this->tiles[position.y][position.x].emplace(RoadTile{position, element});
    }


    std::vector<OptionalRoadTileRef>
    RoadGrid::GetAllNeighbors(Coord position) {
        if (!this->IsInBounds(position)) {
            throw exceptions::OutOfBoundsException("Position out of bounds");
        }
        std::vector<OptionalRoadTileRef> result;
        for (const Coord dir: Constants::Directions) {
            const Coord newPos = position + dir;
            if (this->IsInBounds(newPos)) {
                result.push_back(std::ref(this->GetTile(newPos)));
            }
        }
        return result;
    }

    std::unordered_map<DirectionEnum, std::optional<OptionalRoadTileRef>> RoadGrid::GetNeighborsMap(Coord position) {
        std::unordered_map<DirectionEnum, std::optional<OptionalRoadTileRef>> result;
        for (const DirectionEnum dir: EnumRange<DirectionEnum>()) {
            Coord newPos = position + Coord::Direction(dir);
            if (this->IsInBounds(newPos)) {
                result.insert({dir, std::ref(this->GetTile(newPos))});
            } else {
                result.insert({dir, std::nullopt});
            }
        }
        return result;
    }

    ConnectivityCheckResult RoadGrid::GetPossibleOutboundDirections(Coord position) {
        if (!this->IsInBounds(position)) {
            throw exceptions::OutOfBoundsException("Invalid position");
        }
        std::optional<RoadTile> tile = this->GetTile(position);
        if (tile.has_value()) {
            throw std::invalid_argument("Tile already filled");
        }
        ConnectivityCheckResult result;
        for (const DirectionEnum dir: EnumRange<DirectionEnum>()) {
            ConnectionType conn = this->accessibiltyFromDirection(position + Coord::Direction(dir), dir);
            switch (conn) {
                case ConnectionType::CONNECTION:
                    result.possible.insert(dir);
                    result.required.insert(dir);
                    break;
                case ConnectionType::ACCESSIBLE:
                    result.possible.insert(dir);
                    break;
                case ConnectionType::NONE:
                default:
                    break;
            }
        }

        return result;
    };


    std::ostream &operator<<(std::ostream &os, const RoadGrid &grid) {
        for (int i = 0; i < grid.gridHeight; i++) {
            for (int j = 0; j < grid.gridWidth; j++) {
                if (grid.tiles[i][j].has_value()) {
                    os << grid.tiles[i][j].value().element->character;
                } else {
                    os << '.';
                }
            }
            os << std::endl;
        }
        return os;
    }
}
