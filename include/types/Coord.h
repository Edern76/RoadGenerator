//
// Created by gawei on 11/05/2024.
//

#pragma once

#include <stdexcept>
#include "DirectionEnum.h"

namespace types {
    struct Coord {
        const int x, y;

        Coord() : x(0), y(0) {}

        Coord(int x_val, int y_val) : x(x_val), y(y_val) {}

        static Coord Direction(DirectionEnum dir) {
            switch (dir) {
                case DirectionEnum::NORTH:
                    return {0, 1};
                case DirectionEnum::SOUTH:
                    return {0, -1};
                case DirectionEnum::EAST:
                    return {1, 0};
                case DirectionEnum::WEST:
                    return {-1, 0};
                default:
                    throw std::invalid_argument("Invalid direction");
            }
        }
    };
}
