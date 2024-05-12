//
// Created by gawei on 11/05/2024.
//
#pragma once

#include <unordered_set>
#include <utility>
#include <vector>
#include <set>
#include "Coord.h"

namespace types {
    struct RoadElement {
        signed char character;
        std::set<DirectionEnum> connections; // Because unoredered_set will not play nice

        RoadElement() : character(0), connections() {}

        RoadElement(signed char character_val, std::set<DirectionEnum> connections_val) : character(character_val),
                                                                                          connections(
                                                                                                  std::move(
                                                                                                          connections_val)) {}
    };
}
