//
// Created by gawei on 11/05/2024.
//

#include <optional>
#include <iostream>
#include "../../include/types/RoadGrid.h"

namespace types {
    RoadGrid::RoadGrid(int height, int width) : gridHeight(height), gridWidth(width) {
        this->tiles = new std::optional<RoadElement> *[height];
        for (int i = 0; i < height; i++) {
            this->tiles[i] = new std::optional<RoadElement>[width];
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

    std::ostream &operator<<(std::ostream &os, const RoadGrid &grid) {
        for (int i = 0; i < grid.gridHeight; i++) {
            for (int j = 0; j < grid.gridWidth; j++) {
                if (grid.tiles[i][j].has_value()) {
                    os << grid.tiles[i][j].value().character;
                } else {
                    os << '.';
                }
            }
            os << std::endl;
        }
        return os;
    }
}
