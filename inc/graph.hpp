#pragma once

#include <utility>
#include <vector>
#include "node.hpp"
#include "edge.hpp"

class Graph {
    int destinationIndex = -1;
    std::vector<int> S_COLLECTION;

    Nodes nodes;
    Edges edges;
public:
    Graph() {

    }

    void setDestination(int nodeIndex) {
        destinationIndex = nodeIndex;
    }

    void addStartPoint(int index) {
        S_COLLECTION.push_back(index);
    }

    void addEdge(Edge edge) {
        edges.addEdge(edge);
    }

    void parseNodes() {
        nodes.parseEdges(edges);
    }

};

