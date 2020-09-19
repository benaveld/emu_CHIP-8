#pragma once

#define SDL_MAIN_HANDLED

#include <SDL2/SDL.h>

#define CHIP8_SCREEN_WIDTH 64
#define CHIP8_SCREEN_HEIGHT 32
#define CHIP8_SCREEN_SCALER 10

namespace chip8
{
    class Window
    {
    public:
        Window();

        void clearScreen();

        void render();

    private:
        SDL_Window *window;
        SDL_Renderer *renderer;

        const static unsigned short NR_OF_PIXLES = CHIP8_SCREEN_HEIGHT * CHIP8_SCREEN_WIDTH / 8;
        unsigned char pixles[NR_OF_PIXLES] = {0};
    };
} // namespace chip8