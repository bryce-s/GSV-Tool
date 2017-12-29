//
// Created by Bryce Smith on 12/28/17.
//

#ifndef GSV_TOOL_CONNECTIONLINE_H
#define GSV_TOOL_CONNECTIONLINE_H

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <vector>

class ConnectionLine {

    float lowerX{0};
    float lowerY{0};

    float upperX{0};
    float upperY{0};


public:
    ConnectionLine(const float lowerX_in, const float lowerY_in, const float upperX_in, const float
    upperY_in);

    void renderLines(sf::RenderWindow& window);

};


#endif //GSV_TOOL_CONNECTIONLINE_H
