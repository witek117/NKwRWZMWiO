#include <fstream>
#include "fileParser.hpp"
#include "help.hpp"

void printPath(Node* startNode) {
    if(startNode == nullptr) {
        return;
    }
    while (true) {
        std::cout << startNode->getIndex() << " ";
        startNode = startNode->getParentNode();
        if (startNode == nullptr) {
            break;
        }
    }
}

int main(int argc, char* argv[]) {
    std::string fileName = "test1.txt";
    if(argc > 1) {
        fileName = std::string(argv[1]);
    }
    if (fileName == "-h" || fileName == "--help") {
        printHelpAndExit();
    }

    FileParser fileParser(fileName);
    auto[graph, plan] = fileParser.parse();

    graph.DIJKSTRA(plan.getDestination());

    auto startPoints = plan.getStartPoints();

    uint32_t fastestPath = std::numeric_limits<uint32_t>::max();
    Node* bestStartNode = nullptr;
    for (auto startPoint : startPoints) {
        Node& node = graph.nodes.getNode(startPoint);
        if (fastestPath > node.getLastPathCost()) {
            fastestPath = node.getLastPathCost();
            bestStartNode = &node;
        }
    }

    std::cout << "Best path: ";
    printPath(bestStartNode);

}