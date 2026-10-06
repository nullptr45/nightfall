#include "app.h"
#include "utils/error.h"

#include <SDL3/SDL.h>

namespace nightfall {

App::App(const AppConfig& config)
{
    check(SDL_Init(SDL_INIT_VIDEO), "Failed to initialize SDL3!");

    window_ = SDL_CreateWindow(config.title.c_str(), config.window_width, config.window_height,
                               SDL_WINDOW_VULKAN | SDL_WINDOW_RESIZABLE);
    check(window_, "Unable to open window!");

    SDL_SetWindowFullscreen(window_, config.fullscreen);
    SDL_GetWindowSizeInPixels(window_, &display_width_, &display_height_);
}

App::~App()
{
    SDL_DestroyWindow(window_);
}

void App::run()
{
    bool is_running = true;

    while (is_running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_EVENT_QUIT:
                    is_running = false;
                    break;
                case SDL_EVENT_WINDOW_PIXEL_SIZE_CHANGED:
                    display_width_ = event.window.data1;
                    display_height_ = event.window.data2;
                    break;
                default:
                    break;
            }
        }
    }
}

}  // namespace nightfall
