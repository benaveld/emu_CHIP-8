#pragma once

#include "definitions.hpp"

#define FONT_ADDRESS 0
#define FONT_ADDRESS_STEP 5

namespace chip8
{
    class emulator
    {
    public:
        emulator(unsigned char *a_memory);

        int codef();
        int start();

        unsigned char *m_memory;
        unsigned char m_variables[16] = {0};
        unsigned short m_I = 0;

    private:
        int m_pp = 0x200;
    };
} // namespace chip8