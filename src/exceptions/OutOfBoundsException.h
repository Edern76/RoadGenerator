//
// Created by gawei on 12/05/2024.
//

#pragma once

#include <exception>
#include <cpptrace/cpptrace.hpp>

namespace exceptions {
    struct OutOfBoundsException : public cpptrace::exception_with_message {
        explicit OutOfBoundsException(std::string &&message_arg,
                                      cpptrace::raw_trace &&trace = cpptrace::detail::get_raw_trace_and_absorb()) noexcept
                : cpptrace::exception_with_message(std::move(message_arg), std::move(trace)) {}

    };
}