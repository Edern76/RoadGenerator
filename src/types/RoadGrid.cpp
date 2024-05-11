//
// Created by gawei on 11/05/2024.
//

#include <optional>
#include <iostream>
#include "../../include/types/RoadGrid.h"

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

    bool RoadGrid::IsInBounds(Coord position) const {
        return position.x >= 0 && position.x < this->gridWidth && position.y >= 0 && position.y < this->gridHeight;
    }

    std::optional<RoadTile> &RoadGrid::GetTile(Coord position) {
        if (!this->IsInBounds(position)) {
            throw std::invalid_argument("Position out of bonds");
        }
        return this->tiles[position.y][position.x];
    }

    void RoadGrid::SetTile(Coord position, RoadElement const *element) {
        if (!this->IsInBounds(position)) {
            throw std::invalid_argument("Position out of bounds");
        }
        this->tiles[position.y][position.x].emplace(RoadTile{position, element});
    }

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
