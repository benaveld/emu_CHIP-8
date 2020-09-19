#include "emulator.hpp"
#include "window.hpp"

using namespace chip8;

emulator::emulator(std::byte* a_memory) : m_memory(a_memory){}

int emulator::start() {
    Window win;
    win.render();
    return 0;
}