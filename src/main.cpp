#include <cstdio>
#include <cstddef>

#include "definitions.hpp"
#include "io.hpp"

void printMemoryDump(std::byte *memory, int start, int end)
{
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

    std::byte *data = chip8::io::readProgram(argv[1]);

    printMemoryDump(data, 0x0200, 0x0300);

    delete[] data;

    return 0;
}
