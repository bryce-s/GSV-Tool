# GSV-Tool
A modularized graph search visualizer using the SFML C++ library and custom file input.

<strong>Purpose:</strong> As the name implies, the Graph Search Visualization (GSV) tool provides a visual representation of graph traversal algorithms.
___
<strong>Input:</strong> The GSV tool takes as input the width and height of the display window to be rendered, a number of verities, the vertex positions in order (where _0 ≤ x ≤ width_ and _0 ≤ y ≤ height_) and finally an adjacency list numbered from 0 to numVerticies-1.
Input should be formatted as follows:
```
Width Height
numVertexes
x y
... (include numVertexes pairs..)
x y
--- (a delimiter of some kind)
vertexNumber | firstAdjacentVertex secondAdjacentVertex ... 
...
vertexNumber | firstAdjacentVertex secondAdjacentVertex
```
Here's a specific example:
```
800 500
10
0 | 100 100
1 | 200 200
2 | 300 300
3 | 790 200
4 | 250 450
5 | 625 345
6 | 245 140
7 | 600 400
8 | 550 420
9 | 590 921
---
0 | 1 2
1 | 0 3 6 9
2 | 0 3 4
3 | 1 2 5 7
4 | 2 7
5 | 6
6 | 1 5
7 | 4 8
8 | 7
9 | 1

```

___
