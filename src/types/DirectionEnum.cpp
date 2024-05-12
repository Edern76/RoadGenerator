//
// Created by gawei on 12/05/2024.
//

#include "../../include/types/DirectionEnum.h"
#include <string>
#include <stdexcept>

namespace types {
    std::string DirectionEnumToString(DirectionEnum dir) {
        switch (dir) {
            case DirectionEnum::NORTH:
                return "NORTH";
            case DirectionEnum::SOUTH:
                return "SOUTH";
            case DirectionEnum::EAST:
                return "EAST";
            case DirectionEnum::WEST:
                return "WEST";
            default:
                throw std::invalid_argument("Invalid DirectionEnum");
        }
    }
}
