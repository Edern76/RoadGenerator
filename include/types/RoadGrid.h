//
// Created by gawei on 11/05/2024.
//

#pragma once


#include <optional>
#include "RoadElement.h"

namespace types {
    // Not using template to allow for large grids to fit in heap
    class RoadGrid {
    private:
        std::optional<RoadElement> **tiles;

    public:
        const int gridHeight, gridWidth;

        RoadGrid(int height, int width);

        ~RoadGrid();

        friend std::ostream &operator<<(std::ostream &os, const RoadGrid &grid);

    };
}



