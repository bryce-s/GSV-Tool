//
// Created by Bryce Smith on 12/27/17.
//

#include "Vertex.h"

void Vertex::setColor() {
    vertex.setFillColor(sf::Color::Blue);
}

const sf::Vector2f &Vertex::getPosition() {
    return vertex.getPosition();
}

Vertex::Vertex(const int x_in, const int y_in) {
    assert(x_in >= 0 && y_in >= 0);
    vertex.setPosition(x_in, y_in);
    vertex.setFillColor(sf::Color::Red);
    vertex.setRadius(float{8});
    vertex.setOrigin(float{8}, float{8});
}

Vertex::Vertex(const Vertex &vertex_in) {
    vertex = vertex_in.vertex;
}

void Vertex::loadAdjacencyList(const std::vector<int> &list_in) {
    adjacencyList = list_in;
}

sf::CircleShape &Vertex::getShape() {
    return vertex;
}

std::vector<int> &Vertex::getAdjList() {
    return adjacencyList;
}

bool Vertex::isVisited() {
    return visited;
}

void Vertex::setVisited() {
    visited = true;
    vertex.setFillColor(sf::Color::Blue);
}

