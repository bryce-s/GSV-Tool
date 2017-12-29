//
// Created by Bryce Smith on 12/27/17.
//

#ifndef GSV_TOOL_GSV_H
#define GSV_TOOL_GSV_H

#include <vector>
#include "Vertex.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include "ConnectionLine.h"


class GSV {

    std::vector<Vertex> vertices;

    //returns int as exit code to main.
    int mainLoop(sf::RenderWindow& window);

    //requires: vertices.size() < index
    //inits the vertex and its position
    void loadVertexPosition(size_t index, int x_in, int y_in);

    //requires: vertices.size() < index
    //inits the adj list at vertex[index]
    void loadAdjacencyList(size_t index, std::vector<int>& adjacencyList);

public:



    //note: main loop should be called inside here.
    //      this goes in GSV* so the RenderWindow is in scope with our data from the input file.
    //      also, returns int as exit code to main.
    int initWindow();

    std::pair<int, int> readFromInputFile();

    void renderLines(sf::RenderWindow &window, std::vector<ConnectionLine> &lines);

};


#endif //GSV_TOOL_GSV_H
