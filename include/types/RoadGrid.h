//
// Created by gawei on 11/05/2024.
//

#pragma once


#include <optional>
#include "RoadTile.h"

namespace types {
    // Not using template to allow for large grids to fit in heap
    class RoadGrid {
    private:
        std::optional<RoadTile> **tiles;

    public:
        const int gridHeight, gridWidth;

        RoadGrid(int height, int width);

        ~RoadGrid();

        bool IsInBounds(Coord position) const;

        void SetTile(Coord position, RoadElement const *element);

        std::optional<RoadTile> &GetTile(Coord position);

        friend std::ostream &operator<<(std::ostream &os, const RoadGrid &grid);

    };
}



