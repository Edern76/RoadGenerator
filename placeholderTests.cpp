//
// Created by gawei on 12/05/2024.
//

#include "placeholderTests.h"
#include <iostream>
#include <format>
#include <ranges>
#include <unordered_map>
#include "include/types/RoadGrid.h"
#include "include/types/RoadTile.h"
#include "src/constants/RoadElements.h"

// Keeping this as reference for myself

using namespace Constants;
using types::DirectionEnum;
using types::Coord;
using types::RoadGrid;
using types::RoadElement;
using types::RoadTile;
using types::OptionalRoadTileRef;

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

void doVariousStuff() {
    RoadGrid grid = makePlaceholderGrid();
    std::cout << grid << std::endl;
    auto filledNeighbors = grid.GetAllNeighbors(std::move(Coord{0, 0})) |
                           std::ranges::views::filter(
                                   [](OptionalRoadTileRef opt) { return opt.get().has_value(); });

    for (OptionalRoadTileRef t: filledNeighbors) {
        std::cout << t.get().value().Position << std::endl;
    }

    auto neighbors = grid.GetAllNeighbors(std::move(Coord{2, 2})) |
                     std::ranges::views::filter([](OptionalRoadTileRef opt) { return !opt.get().has_value(); });
    for (OptionalRoadTileRef o: neighbors) {
        o.get().emplace(RoadTile{Coord{}, &Cross});
    }

    std::unordered_map<DirectionEnum, std::optional<OptionalRoadTileRef>> dirMap = grid.GetNeighborsMap(
            std::move(Coord{9, 0}));
    auto nomEmptyEntries = dirMap | std::ranges::views::filter([](auto &pair) { return pair.second.has_value(); });

    for (std::pair<DirectionEnum, std::optional<OptionalRoadTileRef>> entry: nomEmptyEntries) {
        Coord newPos = Coord{9, 0} + Coord::Direction(entry.first);
        entry.second.value().get().emplace(RoadTile{newPos, &NE});
        std::cout << entry.second.value().get()->Position << std::endl;
    }

    std::cout << grid << std::endl;

    types::ConnectivityCheckResult result11 = grid.GetPossibleOutboundDirections(std::move(Coord{1, 1}));
    types::ConnectivityCheckResult result81 = grid.GetPossibleOutboundDirections(std::move(Coord{8, 1}));

    std::cout << "1,1 outbounds possible: "
              << types::DirectionEnumRangeToString(result11.possible)
              << std::endl;
    std::cout << "1,1 outbounds required: "
              << types::DirectionEnumRangeToString(result11.required)
              << std::endl;
    std::cout << "8,1 outbounds possible: "
              << types::DirectionEnumRangeToString(result81.possible)
              << std::endl;
    std::cout << "8,1 outbounds required: "
              << types::DirectionEnumRangeToString(result81.required)
              << std::endl;

}