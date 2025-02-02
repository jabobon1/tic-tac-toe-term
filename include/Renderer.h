//
// Renderer header
//

#ifndef RENDERER_H
#define RENDERER_H
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

class Renderer {

public:
    Renderer() = default;

    ~Renderer() = default;

    void Render(ftxui::Component &component, std::function<bool(ftxui::Event)>);
};

#endif //RENDERER_H
