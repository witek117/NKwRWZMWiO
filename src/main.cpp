#include <fstream>
#include "fileParser.hpp"
#include "help.hpp"

std::string printPath(Node* startNode) {
    std::string out = "";
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

    uint8_t possiblePathCount = 0;
    Node* possiblePaths [10];

    Node* bestStartNode = nullptr;
    for (auto startPoint : startPoints) {
        Node& node = graph.nodes.getNode(startPoint);
        if (fastestPath > node.getLastPathCost()) {
            fastestPath = node.getLastPathCost();
            bestStartNode = &node;

            for (int i = 0; i < possiblePathCount; ++i) {
                possiblePaths[i] = nullptr;
            }

            possiblePathCount = 0;
            possiblePaths[possiblePathCount++] = &node;

        } else if (fastestPath == node.getLastPathCost()) {
            possiblePaths[possiblePathCount++] = &node;
        }
    }

    if (bestStartNode == nullptr) {
        std::cout << "There is no way to help us" << std::endl;
        return 0;
    }

    std::string outData = "";

    std::cout << "Possible paths: \n\r";
    for (int j = 0; j < possiblePathCount; ++j) {
        outData += printPath(possiblePaths[j]) + "\r\n";
        std::cout << std::endl;
    }

    FileSaver::save("out_"+ fileName, "Possible path: \n\r" + outData);
}