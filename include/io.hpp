#pragma once

#include "definitions.hpp"
#include <cstddef>

namespace chip8
{
    class io
    {
        public:
            static std::byte* readProgram(const char *filename);
    };
} // namespace chip8