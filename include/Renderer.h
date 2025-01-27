//
// Renderer header
//

#ifndef RENDERER_H
#define RENDERER_H
#include "ftxui/component/screen_interactive.hpp"  // for ScreenInteractive

class Renderer {
    const ftxui::ScreenInteractive &screen;

public:
    Renderer(): screen(ftxui::ScreenInteractive::FitComponent()) {
    };

    ~Renderer();

    ftxui::Component ComponentFromBoard(std::vector<std::vector<int> > board);

    void Render(ftxui::Component &component, std::function<bool(ftxui::Event)>);
};

#endif //RENDERER_H
