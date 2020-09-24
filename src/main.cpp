#include <cstdio>
#include <stdexcept>
#include <iostream>

#include "definitions.hpp"
#include "io.hpp"
#include "emulator.hpp"

void printMemoryDump(unsigned char *memory, int start, int end)
{
    if (start > end)
    {
        throw std::invalid_argument("printMemoryDumt start is biger then the end\n");
    }

    for (int i = start; i < end; i += 16)
    {
        printf("%04x: ", i);
        for (int j = i; j < i + 16; j += 2)
        {
            printf("%02x%02x ", memory[j], memory[j + 1]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        std::fprintf(stderr, "Needs a programs as seconde argument\n");
        return 1;
    }

    unsigned char *data = chip8::io::readProgram(argv[1]);

    chip8::emulator emu(data);
    int exitCode = emu.start();

    if (exitCode == 0)
    {
        printf("Done\n");
    }
    else
    {
        printMemoryDump(emu.m_memory, 0x0200, 0x0230);

        printMemoryDump(emu.m_memory, 0x500, 0x501);

        for (int i = 0; i < 16; i++)
        {
            printf("%02x ", emu.m_variables[i]);
        }
        printf("\n");

        printf("I = %x\n", emu.m_I);
    }
    char n[50];
    std::cin >> n;

    delete[] data;

    return 0;
}
