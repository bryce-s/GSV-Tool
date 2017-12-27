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

std::pair<int,int> GSV::readFromInputFile() {
    int width, height, numVertices{0};
    std::ifstream inFile("input.txt");
    if (!inFile.is_open()) {
        std::cerr << "no input file found\n";
        exit(1); //using exit in C++ is discouraged because it won't deallocate dynamic memory.
                 //for an application this size, it shouldn't matter.
    }
    inFile >> width >> height >> numVertices;
    assert(width > 0 && height > 0 && numVertices > 0);
    int vertexID, delimiter, xPos, yPos{0};

    for (int i{0}; i < numVertices; i++) {
        inFile >> vertexID >> delimiter >> xPos >> yPos;
        //load pos
    }
    std::string currentLine;
    std::getline(inFile, currentLine); //we capture the separator line

    while (getline(inFile, currentLine)) { //now the adjacency lists
        std::stringstream currentStringStream(currentLine);
        currentStringStream >> vertexID >> delimiter;
        std::vector<int> adjList;
        int vertexConnection{0};
        while (currentStringStream >> vertexConnection) {
            assert(vertexConnection >= 0);
            adjList.push_back(vertexConnection);
        }
        //load adj list
    }
    return {width,height};
}
