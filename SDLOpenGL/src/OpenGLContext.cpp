#include <stdexcept>
#include <iostream>
#include <glad/glad.h>
#include "OpenGLContext.hpp"

namespace SDLOpenGL
{

OpenGLContext::OpenGLContext(SDL_Window* sdlWindow)
    : glContext(SDL_GL_CreateContext(sdlWindow))
{
    if (!glContext)
    {
        throw std::runtime_error("Failure: SDL_GL_CreateContext");
    }

    SDL_GL_MakeCurrent(sdlWindow, glContext);
    SDL_GL_SetSwapInterval(1);

    gladLoadGL(); // Load GLAD so it configures OpenGL

    PrintOpenGLVersion();
}

OpenGLContext::~OpenGLContext()
{
    SDL_GL_DeleteContext(glContext);
}

void OpenGLContext::DrawOpenGLPrimitiveTriangle()
{
    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(-0.5f, -0.5f);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(0.0f, 0.5f);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.5f, -0.5f);
    glEnd();
}

void OpenGLContext::PrintOpenGLVersion()
{
    std::cout << "GL_VENDOR: " << glGetString(GL_VENDOR) << "\n";
    std::cout << "GL_RENDERER: " << glGetString(GL_RENDERER) << "\n";
    std::cout << "GL_VERSION: " << glGetString(GL_VERSION) << "\n";
    std::cout << "GL_SHADING: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << "\n";
}

} // ~namespace SDLOpenGL
