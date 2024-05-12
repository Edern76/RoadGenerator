//
// Created by gawei on 11/05/2024.
//

#pragma once

#include <unordered_map>
#include "../../include/types/Coord.h"

using types::Coord;
using types::DirectionEnum;

namespace Constants {
    const Coord Directions[4] = {Coord::Direction(DirectionEnum::NORTH), Coord::Direction(DirectionEnum::SOUTH),
                                 Coord::Direction(DirectionEnum::EAST), Coord::Direction(DirectionEnum::WEST)};
    const std::unordered_map<DirectionEnum, DirectionEnum> OppositeDirections = {{DirectionEnum::NORTH, DirectionEnum::SOUTH},
                                                                                 {DirectionEnum::SOUTH, DirectionEnum::NORTH},
                                                                                 {DirectionEnum::EAST,  DirectionEnum::WEST},
                                                                                 {DirectionEnum::WEST,  DirectionEnum::EAST}};
}
