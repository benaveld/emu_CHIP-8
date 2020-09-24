#include "emulator.hpp"
#include "window.hpp"

using namespace chip8;

emulator::emulator(unsigned char *a_memory) : m_memory(a_memory)
{
    //Fonts---------------
    // 0
    m_memory[FONT_ADDRESS] = 0b1111;
    m_memory[FONT_ADDRESS + 1] = 0b1001;
    m_memory[FONT_ADDRESS + 2] = 0b1001;
    m_memory[FONT_ADDRESS + 3] = 0b1001;
    m_memory[FONT_ADDRESS + 4] = 0b1111;

    // 1
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP] = 0b0100;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP + 1] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP + 2] = 0b0100;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP + 3] = 0b0100;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP + 4] = 0b0100;

    // 2
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 2] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 2 + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 2 + 2] = 0b0100;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 2 + 3] = 0b0010;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 2 + 4] = 0b1111;

    // 3
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 3] = 0b1110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 3 + 1] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 3 + 2] = 0b1100;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 3 + 3] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 3 + 4] = 0b1110;

    // 4
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 4] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 4 + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 4 + 2] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 4 + 3] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 4 + 4] = 0b1000;

    // 5
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 5] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 5 + 1] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 5 + 2] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 5 + 3] = 0b0001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 5 + 4] = 0b1111;

    // 6
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 6] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 6 + 1] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 6 + 2] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 6 + 3] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 6 + 4] = 0b1111;

    // 7
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 7] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 7 + 1] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 7 + 2] = 0b0100;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 7 + 3] = 0b0010;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 7 + 4] = 0b0001;

    // 8
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 8] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 8 + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 8 + 2] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 8 + 3] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 8 + 4] = 0b0110;

    // 9
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 9] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 9 + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 9 + 2] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 9 + 3] = 0b1010;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 9 + 4] = 0b1111;

    // a
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xa] = 0b0110;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xa + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xa + 2] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xa + 3] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xa + 4] = 0b1001;

    // b
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xb] = 0b0111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xb + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xb + 2] = 0b0111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xb + 3] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xb + 4] = 0b0111;

    // c
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xc] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xc + 1] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xc + 2] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xc + 3] = 0b1000;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xc + 4] = 0b1111;

    // d
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xd] = 0b0111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xd + 1] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xd + 2] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xd + 3] = 0b1001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xd + 4] = 0b0111;

    // e
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xe] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xe + 1] = 0b0001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xe + 2] = 0b0111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xe + 3] = 0b0001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xe + 4] = 0b1111;

    // f
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xf] = 0b1111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xf + 1] = 0b0001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xf + 2] = 0b0111;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xf + 3] = 0b0001;
    m_memory[FONT_ADDRESS + FONT_ADDRESS_STEP * 0xf + 4] = 0b0001;
}

int emulator::codef()
{
    unsigned char vx = m_memory[m_pp] & 0xf;
    switch (m_memory[m_pp + 1])
    {
    case 0x00:
        return 0;

    case 0x29:
        m_I = FONT_ADDRESS + FONT_ADDRESS_STEP * m_variables[vx];
        break;

    case 0x33:
        m_memory[m_I] = m_variables[vx] / 100;
        m_memory[m_I + 1] = (m_variables[vx] % 100) / 10;
        m_memory[m_I + 2] = m_variables[vx] % 10;
        break;

    case 0x65:
        for (int i = 0; i <= vx; i++)
        {
            m_variables[i] = m_memory[m_I + i];
        }
        break;

    default:
        fprintf(stderr, "command fx%02x not implemented yet\n", m_memory[m_pp + 1]);
        return 1;
        break;
    }
    return 0;
}

int emulator::start()
{
    Window win;
    int returnCode;
    while (true)
    {
        switch (m_memory[m_pp] >> 4)
        {
        case 0:
            if (m_memory[m_pp] == 00 && m_memory[m_pp + 1] == 0xe0)
            {
                win.clearScreen();
            }
            else if (m_memory[m_pp] == 00 && m_memory[m_pp + 1] == 0xee)
            {
                fprintf(stderr, "need to implement return\n");
                return 1;
            }
            else
            {
                fprintf(stderr, "need to call machin subrutin\n");
                return 1;
            }
            break;

        case 6:
            m_variables[m_memory[m_pp] & 0xf] = m_memory[m_pp + 1];
            break;

        case 7:
            m_variables[m_memory[m_pp] & 0xf] += m_memory[m_pp + 1];
            break;

        case 0xa:
            m_I = (m_memory[m_pp] & 0xf) << 8;
            m_I = m_I | m_memory[m_pp + 1];
            break;

        case 0xd:
            win.drawSprite(m_I,
                           m_variables[m_memory[m_pp] & 0xf],
                           m_variables[m_memory[m_pp + 1] >> 4],
                           m_memory[m_pp + 1] & 0xf,
                           m_memory,
                           &m_variables[0xf]);
            break;

        case 0xf:
            if (m_memory[m_pp + 1] == 0x00)
            {
                win.render();
                return 0;
            }
            returnCode = codef();
            if (returnCode != 0)
            {
                return returnCode;
            }
            break;

        default:
            fprintf(stderr, "%02x%02x is not implented yet\n", m_memory[m_pp], m_memory[m_pp + 1]);
            return 1;
            break;
        }
        m_pp += 2;
    }
    return 0;
}