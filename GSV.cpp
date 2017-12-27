//
// Created by Bryce Smith on 12/27/17.
//

#include "GSV.h"

using namespace sf;

int GSV::mainLoop(sf::RenderWindow &window) {
    while (true) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
            return 0;
        }
        window.clear(sf::Color::Black);
        window.display();
    }
    return 1; //not reachable
}

int GSV::initWindow() {
    constexpr int windowWidth{800};
    constexpr int windowHeight{600};

    sf::RenderWindow window({windowWidth,windowHeight,32}, "Graph Search Visualizer");
    window.setFramerateLimit(60);

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)) { //constant rendering of window.
            return mainLoop(window);
        }
    }
    return 1;
}