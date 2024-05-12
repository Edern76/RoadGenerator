//
// Created by gawei on 11/05/2024.
//

#pragma once

#include <stdexcept>
#include "DirectionEnum.h"

namespace types {
    struct Coord {
        int x, y;

        Coord() : x(-1), y(-1) {}

        Coord(int x_val, int y_val) : x(x_val), y(y_val) {}

        Coord(const Coord &other) : x(other.x), y(other.y) {}

        Coord(Coord &other) : x(other.x), y(other.y) {}

        Coord(const Coord &&other) : x(other.x), y(other.y) {}

        static Coord Direction(DirectionEnum dir) {
            switch (dir) {
                case DirectionEnum::NORTH:
                    return {0, -1};
                case DirectionEnum::SOUTH:
                    return {0, 1};
                case DirectionEnum::EAST:
                    return {1, 0};
                case DirectionEnum::WEST:
                    return {-1, 0};
                default:
                    throw std::invalid_argument("Invalid direction");
            }
        }

        Coord operator+(const Coord &other) const {
            return Coord{x + other.x, y + other.y};
        }

        Coord &operator=(const Coord &other) {
            x = other.x;
            y = other.y;
            return *this;
        }

        bool operator==(const Coord &other) const {
            return x == other.x && y == other.y;
        }

        friend std::ostream &operator<<(std::ostream &os, const Coord &coord);
    };
}
