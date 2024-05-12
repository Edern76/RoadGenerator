//
// Created by gawei on 11/05/2024.
//

#pragma once

#include "../../include/types/RoadElement.h"
#include <set>

using types::RoadElement;
using types::Coord;
using types::DirectionEnum;

namespace Constants {
    // ╬
    const RoadElement Cross = RoadElement{char(206), std::set<DirectionEnum>{DirectionEnum::NORTH,
                                                                             DirectionEnum::SOUTH,
                                                                             DirectionEnum::WEST,
                                                                             DirectionEnum::EAST}};
    // ╚
    const RoadElement NE = RoadElement{char(200), std::set<DirectionEnum>{DirectionEnum::NORTH,
                                                                          DirectionEnum::EAST}};
}

