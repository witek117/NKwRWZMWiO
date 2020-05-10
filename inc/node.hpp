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
    Node* parentNode = nullptr;
    int lastPathCost = -1;
    int indexNumber;
    uint32_t uID;
public:
    Node* getParentNode() {
        return parentNode;
    }

    uint32_t getLastPathCost() {
        return lastPathCost;
    }

    void setLastPathCost(int cost ) {
        lastPathCost = cost;
    }

    void setPreviousNode(Node* node) {
        parentNode = node;
    }
    std::vector<Edge> edges;

    Node(int indexNumber, uint32_t uID) : indexNumber(indexNumber), uID(uID) { }

    void addEdges(Edge edge) {
        if (!findEdge(edges, edge)) {
            edges.emplace_back(edge);
        }
    }

    int getIndex() {
        return indexNumber;
    }

    uint32_t getUID() {
        return uID;
    }
};

class Nodes {
    uint32_t nodesCount = 0;
    int findNode(std::vector<Node>& nodes, int index) {
        for (unsigned int i = 0; i < nodes.size() ; i++) {
            if (nodes[i].getIndex() == index) {
                return i;
            }
        }
        return -1;
    }


public:
    void parseEdges(Edges edges) {
        nodesCount = 0;

        for(auto itemEdge: edges.items) {
            int start =  itemEdge.getStartIndex();
            int stop = itemEdge.getStopIndex();

            int nodeIndex = findNode(items, start);
            if (nodeIndex == -1) {
                items.emplace_back(start, nodesCount++);
                items[items.size() - 1].addEdges(itemEdge);
            } else {
                items[nodeIndex].addEdges(itemEdge);
            }

            nodeIndex = findNode(items, stop);
            if (nodeIndex == -1) {
                items.emplace_back(stop, nodesCount++);
                items[items.size() - 1].addEdges(itemEdge);
            } else {
                items[nodeIndex].addEdges(itemEdge);
            }
        }
    }

    Node& getNode(int nodeIndex) {
        for (auto& node : items) {
            if (node.getIndex() == nodeIndex) {
                return node;
            }
        }
        return items.at(0);
    }

    uint32_t size() {
        return nodesCount;
    }

    std::vector<Node> items;
};