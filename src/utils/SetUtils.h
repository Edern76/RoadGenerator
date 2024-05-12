//
// Created by gawei on 12/05/2024.
//

#pragma once

#include <set>

namespace utils::sets {
    template<typename T>
    bool Contains(const std::set<T> &set, const T &value) {
        return set.find(value) != set.end();
    }

}
