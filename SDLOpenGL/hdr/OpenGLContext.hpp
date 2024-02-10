#pragma once
#include <SDL.h>
#include <iostream>

namespace SDLOpenGL
{
    class OpenGLContext final
    {
    public:
        OpenGLContext(SDL_Window* sdlWindow);
        ~OpenGLContext();

        void DrawOpenGLPrimitiveTriangle();

    private:
        void PrintOpenGLVersion();

    private:
        SDL_GLContext glContext {nullptr};
    };

} // ~namespace SDLOpenGL
