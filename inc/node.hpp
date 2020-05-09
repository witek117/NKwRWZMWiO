#pragma once

#include <vector>
#include "edge.hpp"

class Node {
    bool findEdge(std::vector<Edge>& edges, Edge edge) {
        for (auto edge_m : edges) {
            if (edge_m == edge) {
                return true;
            }
        }
        return false;
    }

    int indexNumber;
    std::vector<Edge> edges;

public:
    Node(int indexNumber) : indexNumber(indexNumber) {
//        edges.clear();
    }

    void addEdges(Edge edge) {
        if (!findEdge(edges, edge)) {
            edges.emplace_back(edge);
        }
//        edges.emplace_back(edge);
    }

    int getIndex() {
        return indexNumber;
    }
};

class Nodes {

    int findNode(std::vector<Node>& nodes, int index) {
        for (unsigned int i = 0; i < nodes.size() ; i++) {
            if (nodes[i].getIndex() == index) {
                return i;
            }
        }
        return -1;
    }



    std::vector<Node> items;

public:
    void parseEdges(Edges edges) {
        for(auto itemEdge: edges.items) {
            int start =  itemEdge.getStartIndex();
            int stop = itemEdge.getStopIndex();

            int nodeIndex = findNode(items, start);
            if (nodeIndex == -1) {
                items.emplace_back(start);
                items[items.size() - 1].addEdges(itemEdge);
            } else {
                items[nodeIndex].addEdges(itemEdge);
            }

            nodeIndex = findNode(items, stop);
            if (nodeIndex == -1) {
                items.emplace_back(stop);
                items[items.size() - 1].addEdges(itemEdge);
            } else {
                items[nodeIndex].addEdges(itemEdge);
            }
        }
    }
};