#pragma once

#include <utility>
#include <vector>
#include "node.hpp"
#include "edge.hpp"

class Graph {
public:
    Nodes nodes;
    Edges edges;

    Graph() {

    }

    void addEdge(Edge edge) {
        edges.addEdge(edge);
    }

    void parseNodes() {
        nodes.parseEdges(edges);
    }

    bool isAllDone(bool doneIndexes [], uint32_t size) {
        for (uint32_t  i = 0; i < size; i++) {
            if (!doneIndexes[i]) {
                return false;
            }
        }
        return true;
    }

    void DIJKSTRA(int startIndex) {
        int actualIndex = startIndex;
        Node actualNode = nodes.getNode(actualIndex);

        bool doneIndexes [nodes.size()];
        uint32_t costsToStartIndex[nodes.size()];
        Node* previousNode[nodes.size()];
        for (unsigned int i =0; i < nodes.size(); i++) {
            doneIndexes[i] = false;
            costsToStartIndex[i] = std::numeric_limits<uint32_t>::max();
            previousNode[i] = nullptr;
        }

        std::vector<uint32_t> friendsToVisit;
        uint32_t friendIterator = 0;
        costsToStartIndex[actualNode.getUID()] = 0;

        while (!isAllDone(doneIndexes, nodes.size())) {
            doneIndexes[actualNode.getUID()] = true;
            for (auto edgeTemp : actualNode.edges) {
                int friendNodeID = -1;
                if (edgeTemp.getStopIndex() == actualIndex) {
                    friendNodeID = nodes.getNode(edgeTemp.getStartIndex()).getUID();
                } else {
                    friendNodeID = nodes.getNode(edgeTemp.getStopIndex()).getUID();
                }

                if (!doneIndexes[friendNodeID]) {
                    friendsToVisit.emplace_back(friendNodeID);
                }

                uint32_t pathCost = edgeTemp.getCost() +  costsToStartIndex[actualNode.getUID()];

                if (costsToStartIndex[friendNodeID] > pathCost) {
                    costsToStartIndex[friendNodeID] = pathCost;
                    previousNode[friendNodeID] = &nodes.getNode(actualIndex); // pointer to reference
                }
            }

            while (true) {
                if (friendIterator == friendsToVisit.size()) {
                    break;
                }
                int friendToVisit = friendsToVisit.at(friendIterator++);
                if (previousNode[friendToVisit] != nullptr && !doneIndexes[friendToVisit]) {
                    actualNode = nodes.items[friendToVisit];
                    actualIndex = actualNode.getIndex();
                    break;
                }
            }
        }

        for(unsigned int i = 0; i < nodes.size(); i++) {
            nodes.items[i].setLastPathCost(costsToStartIndex[i]);
            nodes.items[i].setPreviousNode(previousNode[i]);
        }
    }
};

