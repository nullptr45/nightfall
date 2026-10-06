#pragma once

#include <string>

struct SDL_Window;

namespace nightfall {

struct AppConfig {
    std::string title = "Nightfall Engine";

    int window_width = 1280;
    int window_height = 720;

    bool fullscreen = false;
};

class App {
public:
    App(const AppConfig& config = {});
    ~App();

    App(const App&) = delete;
    App& operator=(const App&) = delete;

    App(App&&) = delete;
    App& operator=(App&&) = delete;

    void run();

private:
    SDL_Window* window_;

    int display_width_;
    int display_height_;
};

}  // namespace nightfall
