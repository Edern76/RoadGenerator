//
// Created by gawei on 11/05/2024.
//

#pragma once

#include "../../include/types/RoadElement.h"

using types::RoadElement;
using types::Coord;
using types::DirectionEnum;

namespace Constants {
    // ╬
    const RoadElement Cross = RoadElement{char(206), std::vector<Coord>{Coord::Direction(DirectionEnum::NORTH),
                                                                        Coord::Direction(DirectionEnum::SOUTH),
                                                                        Coord::Direction(DirectionEnum::WEST),
                                                                        Coord::Direction(DirectionEnum::EAST)}};
    // ╚
    const RoadElement NE = RoadElement{char(200), std::vector<Coord>{Coord::Direction(DirectionEnum::NORTH),
                                                                     Coord::Direction(DirectionEnum::EAST)}};
}

