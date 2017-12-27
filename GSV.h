//
// Created by Bryce Smith on 12/27/17.
//

#ifndef GSV_TOOL_GSV_H
#define GSV_TOOL_GSV_H

#include <vector>
#include "Vertex.h"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class GSV {

    std::vector<Vertex> vertices;

    //returns int as exit code to main.
    int mainLoop(sf::RenderWindow& window);
public:



    //note: main loop should be called inside here.
    //      this goes in GSV* so the RenderWindow is in scope with our data from the input file.
    //      also, returns int as exit code to main.
    int initWindow();

};


#endif //GSV_TOOL_GSV_H
