//
// Created by Bryce Smith on 12/27/17.
//

#ifndef GSV_TOOL_VERTEX_H
#define GSV_TOOL_VERTEX_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cassert>
#include <vector>

class Vertex {

    sf::CircleShape vertex;
    std::vector<int> adjacencyList;

public:
    Vertex(){};
    Vertex(int x_in, int y_in);
    Vertex(const Vertex& vertex_in);
    void setColor();
    const sf::Vector2f& getPosition();
    void loadAdjacencyList(const std::vector<int>& list_in);


};


#endif //GSV_TOOL_VERTEX_H
