//
// Created by gawei on 11/05/2024.
//

#pragma once

#include "../../include/types/Coord.h"

using types::Coord;
using types::DirectionEnum;

namespace Constants {
    const Coord Directions[4] = {Coord::Direction(DirectionEnum::NORTH), Coord::Direction(DirectionEnum::SOUTH),
                                 Coord::Direction(DirectionEnum::EAST), Coord::Direction(DirectionEnum::WEST)};
}
