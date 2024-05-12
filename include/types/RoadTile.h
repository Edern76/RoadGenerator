//
// Created by gawei on 11/05/2024.
//

#pragma once

#include "RoadElement.h"

namespace types {
    struct RoadTile {
        Coord Position;
        RoadElement const *element;
    };
    using OptionalRoadTileRef = std::reference_wrapper<std::optional<RoadTile>>;
}
