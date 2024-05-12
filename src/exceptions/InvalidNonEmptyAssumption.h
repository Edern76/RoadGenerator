//
// Created by gawei on 12/05/2024.
//

#pragma once

#include <exception>

namespace exceptions {
    struct InvalidNonEmptyAssumption : public std::exception {
        const char *msg;

        explicit InvalidNonEmptyAssumption(const char *msg) : msg(msg) {}

        [[nodiscard]]
        const char *what() const noexcept override {
            return msg;
        }
    };
}
