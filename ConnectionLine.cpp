//
// Created by Bryce Smith on 12/28/17.
//

#include "ConnectionLine.h"

void ConnectionLine::renderLines(sf::RenderWindow& window) {
    static const int numLines = 2;
    sf::VertexArray lines(sf::LinesStrip, numLines);
    lines[0].position = sf::Vector2f(lowerX, lowerY);
    lines[1].position = sf::Vector2f(upperX, upperY);
    window.draw(lines);

}

ConnectionLine::ConnectionLine(const float lowerX_in, const float lowerY_in, const float upperX_in,
                               const float upperY_in) : lowerX(lowerX_in), lowerY(lowerY_in),
                                                        upperX(upperX_in), upperY(upperY_in) {

}


