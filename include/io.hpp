#pragma once

#include "definitions.hpp"

namespace chip8
{
    class io
    {
        public:
            static unsigned char* readProgram(const char *filename);
    };
} // namespace chip8