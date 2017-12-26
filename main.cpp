#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "SettingPack.h"

using namespace sf;


int mainLoop(SettingPack& settings, RenderWindow& window) {
    while (true) {
        if (Keyboard::isKeyPressed(Keyboard::Key::Escape)) {
            return 0;
        }
        window.clear(sf::Color::Black);
        window.display();
    }
}


int main() {
    constexpr int windowWidth{800};
    constexpr int windowHeight{600};
    SettingPack settings;

    sf::RenderWindow window({windowWidth,windowHeight,32}, "Graph Search Visualizer");
    window.setFramerateLimit(60);

    while(window.isOpen()){
        Event event;
        while (window.pollEvent(event)) { //constant rendering of window.
            return mainLoop(settings, window);
        }
    }
    return 0;
}