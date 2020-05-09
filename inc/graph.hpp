#pragma once

#include <utility>
#include <vector>
#include "node.hpp"
#include "edge.hpp"

class Graph {
    int destinationIndex = -1;
    std::vector<int> S_COLLECTION;

    std::vector<Node> nodes;

    Edges edges;
public:
    Graph() {

    }

    void setDestination(int nodeIndex) {
        destinationIndex = nodeIndex;
    }

//    void setSCollection( std::vector<int> S_coll) {
//        S_COLLECTION = std::move(S_coll);
//    }

    void addStartPoint(int index) {
        S_COLLECTION.push_back(index);
    }

//    void addNode(Node node) {
//        nodes.push_back(node);
//    }

    void addEdge(Edge edge) {
        edges.addEdge(edge);
    }

    void parseNodes() {
        nodes = edges.getNodes();
//        edges.getNodes();
    }

};

