#pragma once

#include "node.hpp"
#include <algorithm>

class Edge {
    int startIndex;
    int stopIndex;
    int cost = 1;

public:
    Edge(int start, int stop) : startIndex(start), stopIndex(stop) {

    }

    int getStartIndex() {
        return startIndex;
    }

    int getStopIndex() {
        return stopIndex;
    }
};

class Edges {
    std::vector<Edge> items;

    bool findNode(std::vector<Node>& nodes, int index) {
        for (auto node : nodes) {
            if (node.getIndex() == index) {
                return true;
            }
        }
        return false;
    }

public:
    Edges() { }

    void addEdge(Edge edge) {
        items.push_back(edge);
    }

    std::vector<Node> getNodes() {
        std::vector<Node> nodes;
        for(auto item: items) {

            int start =  item.getStartIndex();
            int stop = item.getStopIndex();
            if (!findNode(nodes, start)) {

                nodes.push_back(start);
            }

            if (!findNode(nodes, stop)) {
                nodes.push_back(stop);
            }
//            if (std::find(nodes.begin(), nodes.end(), item.getStartIndex()) != nodes.end())  {
//                nodes.emplace_back(item.getStartIndex());
//            }
//
//            if (std::find(nodes.begin(), nodes.end(), item.getStopIndex()) != nodes.end())  {
//                nodes.emplace_back(item.getStopIndex());
//            }
        }
        return nodes;
    }
};