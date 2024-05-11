#include <iostream>
#include <format>
#include "include/types/RoadGrid.h"
#include "src/constants/RoadElements.h"

using namespace Constants;
using types::DirectionEnum;
using types::Coord;
using types::RoadGrid;
using types::RoadElement;
using types::RoadTile;

const std::locale loc{"en_US.UTF-8"};

RoadGrid makePlaceholderGrid() {
    RoadGrid grid = RoadGrid(10, 10);
    grid.SetTile(std::move(Coord{0, 0}), &Constants::Cross);
    grid.SetTile(std::move(Coord{0, 1}), &Constants::Cross);
    std::optional<RoadTile> &optTile = grid.GetTile(std::move(Coord{0, 1}));
    if (optTile.has_value()) {
        RoadTile &tile = optTile.value();
        tile.element = &Constants::NE;
    }
    return grid;
}

int main() {
    RoadGrid grid = makePlaceholderGrid();
    std::cout << grid << std::endl;
    return 0;
}
