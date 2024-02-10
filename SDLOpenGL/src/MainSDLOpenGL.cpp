#define SDL_MAIN_HANDLED

#include <iostream>
#include "SDLWindow.hpp"

int main()
{
    try {
        SDLOpenGL::SDLWindow sdlWindow("SDL Window (with OpenGL)");
        sdlWindow.RunFrameLoop();
    }
    catch (const std::runtime_error& e)
    {
        std::cout << e.what() << "\n";
    }
}
