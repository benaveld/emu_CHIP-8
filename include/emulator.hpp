#pragma once

#include <cstddef>

#include "definitions.hpp"


namespace chip8
{
    class emulator
    {
    public:
        emulator(std::byte* a_memory);

        int start();

    private:
        std::byte* m_memory;
        int m_pp=0;
        char m_x, m_y;
        char reg[16];

    };
} // namespace chip8