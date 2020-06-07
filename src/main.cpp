#include <fstream>
#include "fileParser.hpp"
#include "help.hpp"

std::string printPath(Node* startNode) {
    std::string out = "Best path ";
    if(startNode == nullptr) {
        return "";
    }
    while (true) {
        out += std::to_string(startNode->getIndex()) + " ";
        startNode = startNode->getParentNode();
        if (startNode == nullptr) {
            break;
        }
    }
    std::cout << out;
    return out;
}

int main(int argc, char* argv[]) {
    std::string fileName = "test1.txt";
    if(argc > 1) {
        fileName =  std::string(argv[1]);
    }
    if (fileName == "-h" || fileName == "--help") {
        printHelpAndExit();
    }

    std::cout << fileName << std::endl;

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

    std::string outData = printPath(bestStartNode);

    FileSaver::save("out_"+ fileName, "Best path: " + outData);
}