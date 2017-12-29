//
// Created by Bryce Smith on 12/28/17.
//

#ifndef GSV_TOOL_DFS_H
#define GSV_TOOL_DFS_H

#include <vector>
#include <Vertex.h>
#include "Vertex.h"
#include <stack>

class DFS {

public:
    static DFS(std::vector<Vertex>& vert) {
        std::stack<unsigned int> vertexStack;
        vertexStack.push(0);
        vert[0].setVisited();
        while (!vertexStack.empty()) {
            unsigned int currentVertex = vertexStack.top();
            vertexStack.pop();
            for (auto eachChild : vert[currentVertex].getAdjList()) {
                if (!vert[eachChild].isVisited()) {

                } else {
                    vert[eachChild].setVisited();
                    vertexStack.push(static_cast<unsigned int>(eachChild));
                }
            }
        }
    }
};

#endif //GSV_TOOL_DFS_H
