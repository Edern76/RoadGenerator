//
// Created by gawei on 12/05/2024.
//

#pragma once

template<class T>
struct EnumRange {
    struct Iterator {
        explicit Iterator(int v) : value(v) {}

        void operator++() { ++value; }

        bool operator!=(Iterator rhs) { return value != rhs.value; }

        T operator*() const { return static_cast<T>(value); }

        int value = 0;
    };

    Iterator begin() const { return Iterator(0); }

    Iterator end() const { return Iterator(static_cast<int>(T::MAX) + 1); }
};
