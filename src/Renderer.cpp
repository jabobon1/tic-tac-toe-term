//
// Renderer source
//
#include <map>
#include <ftxui/component/event.hpp>
#include <ftxui/component/component.hpp>

#include "../include/Renderer.h"

void Renderer::Render(ftxui::Component &component, std::function<bool(ftxui::Event)> callback) {
    auto screen = ftxui::ScreenInteractive::FitComponent();

    component = CatchEvent(component, [this,&callback,&screen](const ftxui::Event &event) {
        if (event == ftxui::Event::Escape || event.input() == "q") {
            screen.ExitLoopClosure()();
            return false;
        }
        return callback(event);
    });

    screen.Loop(component);
}
