#include "window.hpp"

using namespace chip8;

Window::Window()
{
    SDL_CreateWindowAndRenderer(CHIP8_SCREEN_WIDTH * CHIP8_SCREEN_SCALER, CHIP8_SCREEN_HEIGHT * CHIP8_SCREEN_SCALER, 0, &window, &renderer);
}

void Window::clearScreen()
{
    for (int i = 0; i < NR_OF_PIXLES; i++)
    {
        pixles[i] = 0;
    }
}

void Window::render()
{
    SDL_Rect rect{0, 0, CHIP8_SCREEN_SCALER, CHIP8_SCREEN_SCALER};

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    for (short i = 0; i < NR_OF_PIXLES; i++)
    {
        for (unsigned char j = 0; j < 8; j++)
        {
            if ((pixles[i] & (1 << j)) > 0)
            {
                int nr = (i * 8 + j);
                rect.x = (nr % CHIP8_SCREEN_WIDTH) * CHIP8_SCREEN_SCALER;
                rect.y = floor(nr / CHIP8_SCREEN_WIDTH) * CHIP8_SCREEN_SCALER;
                SDL_RenderFillRect(renderer, &rect);
            }
        }
    }

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderPresent(renderer);
}
