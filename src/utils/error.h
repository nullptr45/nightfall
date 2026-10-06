#pragma once

#include <format>
#include <source_location>
#include <stdexcept>

namespace nightfall {

struct Error : public std::runtime_error {
    constexpr Error(std::string_view     msg,
                    std::source_location loc = std::source_location::current()) :
        std::runtime_error(std::format("ERROR: {}\nFILE: {}\nFUNCTION: {}\nLINE: {}", msg,
                                       loc.file_name(), loc.function_name(), loc.line()))
    {}
};

inline void check(bool condition, std::string_view msg = "",
                  std::source_location loc = std::source_location::current())
{
    if (!condition) [[unlikely]] {
        throw Error(msg, loc);
    }
}

}  // namespace nightfall
