//
// Created by gawei on 11/05/2024.
//

#pragma once

#include "RoadElement.h"

namespace types {
    struct RoadTile {
        Coord Position;
        std::optional<RoadElement const *> element;

        RoadTile() : Position(Coord()), element(std::nullopt) {}

        RoadTile(Coord pos) : Position(pos), element(std::nullopt) {}

        RoadTile(Coord pos, RoadElement const *elem) : Position(pos), element(elem) {}

        RoadTile(const RoadTile &other) : Position(other.Position), element(other.element) {}

        RoadTile(RoadTile &other) : Position(other.Position), element(other.element) {}

        RoadTile &operator=(const RoadTile &other) {
            Position = other.Position;
            element = other.element;
            return *this;
        }
    };

    using OptionalRoadTileRef = std::reference_wrapper<RoadTile>;
}
