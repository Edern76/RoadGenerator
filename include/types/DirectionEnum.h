//
// Created by gawei on 11/05/2024.
//

#pragma once

#include <string>

template<class R, class Value>
concept range_over = std::ranges::range<R> &&
                     std::same_as<std::ranges::range_value_t<R>, Value>;

namespace types {
    enum class DirectionEnum {
        NORTH,
        SOUTH,
        EAST,
        WEST,
        MAX = WEST
    };

    std::string DirectionEnumToString(DirectionEnum dir);

    template<range_over<DirectionEnum> Range>
    std::string DirectionEnumRangeToString(const Range &range) {
        std::string result;
        for (const auto &dir: range) {
            result += DirectionEnumToString(dir);
            result += ", ";
        }
        return result;
    }
}

