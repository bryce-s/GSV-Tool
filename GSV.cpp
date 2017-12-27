//
// Created by Bryce Smith on 12/27/17.
//

#include "GSV.h"

//no SF namespace, since vertex is also a SF library object

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
    auto widthHeight = readFromInputFile();
    const unsigned int windowWidth = static_cast<unsigned int>(widthHeight.first);
    const unsigned int windowHeight = static_cast<unsigned int>(widthHeight.second);
    sf::RenderWindow window({windowWidth,windowHeight,32}, "Graph Search Visualizer");
    window.setFramerateLimit(60);

    while (window.isOpen()){
        sf::Event event;
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
    vertices.resize(static_cast<size_t>(numVertices));
    int vertexID, xPos, yPos{0};
    char delimiter;
    for (int i{0}; i < numVertices; i++) {
        inFile >> vertexID >> delimiter >> xPos >> yPos;
        loadVertexPosition(static_cast<size_t>(vertexID), xPos, yPos);
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
        loadAdjacencyList(static_cast<size_t>(vertexID), adjList);
    }
    return {width,height};
}

void GSV::loadVertexPosition(size_t index, int x_in, int y_in) {
    assert(vertices.size() > index);
    vertices[index] = Vertex{x_in, y_in}; //since it's presized we'll just copy it over.
}

void GSV::loadAdjacencyList(size_t index, std::vector<int>& adjacencyList) {
    assert(vertices.size() > index);
    vertices[index].loadAdjacencyList(adjacencyList);
}
