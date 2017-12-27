//
// Created by Bryce Smith on 12/27/17.
//

#ifndef GSV_TOOL_VERTEX_H
#define GSV_TOOL_VERTEX_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cassert>

class Vertex {

    sf::CircleShape vertex;

public:

    Vertex(int x_in, int y_in);
    void setColor();
    const sf::Vector2f& getPosition();

};


#endif //GSV_TOOL_VERTEX_H
