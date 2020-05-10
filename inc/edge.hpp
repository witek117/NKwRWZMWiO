#pragma once

//#include "node.hpp"
#include <algorithm>

class Edge {
    int startIndex;
    int stopIndex;
    int cost = 1;

public:
    bool operator==(const Edge& lhs) {
        return startIndex == lhs.startIndex && stopIndex == lhs.stopIndex;
    }

    Edge(int start, int stop) : startIndex(start), stopIndex(stop) {

    }

    int getStartIndex() {
        return startIndex;
    }

    int getStopIndex() {
        return stopIndex;
    }

    int getCost() {
        return cost;
    }
};

class Edges {

public:
    Edges() { }

    void addEdge(Edge edge) {
        items.push_back(edge);
    }

    std::vector<Edge> items;
};