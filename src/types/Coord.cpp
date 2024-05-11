//
// Created by gawei on 11/05/2024.
//

#include <ostream>
#include <format>
#include "../../include/types/Coord.h"

namespace types {
    std::ostream &operator<<(std::ostream &os, const Coord &coord) {
        os << "{x:" << coord.x << ";y:" << coord.y << "}";
        return os;
    }
}

namespace std {
    template<class TChar>
    struct formatter<types::Coord, TChar> {
        template<typename TContext>
        auto parse(TContext &pc) {
            return pc.end;
        }

        template<typename TContext>
        auto format(types::Coord &c, TContext &fc) {
            return std::format_to(fc.out, "{x:{}, y:{}}", c.x, c.y);
        }

        template<typename TContext>
        auto vformat(types::Coord &c, TContext &fc) {
            return std::vformat_to(fc.out, std::string_view{"{x:{}, y:{}}"}, c.x, c.y);
        }
    };
}
