//
// Created by Bryce Smith on 12/28/17.
//

#ifndef GSV_TOOL_DFS_H
#define GSV_TOOL_DFS_H

#include <vector>
#include "Vertex.h"
#include <stack>

template<class GSV>
    static int DFS_(std::vector<Vertex> &vert, GSV &mainGSV, sf::RenderWindow &window) {
        std::stack<unsigned int> vertexStack;
        std::vector<ConnectionLine> lines;
        vertexStack.push(0);
        vert[0].setVisited();
        while (!vertexStack.empty()) {
            unsigned int currentVertex = vertexStack.top();
            vertexStack.pop();
            for (auto eachChild : vert[currentVertex].getAdjList()) {
                if (!vert[eachChild].isVisited()) {
                    mainGSV.runDisplay(window, lines);
                    vert[eachChild].setVisited();
                    vertexStack.push(static_cast<unsigned int>(eachChild));
                } else {

                    mainGSV.runDisplay(window, lines);


                }
            }
        }
        return 0;
    }

#endif //GSV_TOOL_DFS_H
