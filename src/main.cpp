//#include <iostream>
#include <dirent.h>
#include <fstream>
#include "fileParser.hpp"

static std::string testName = "test1.txt";

int main() {
    FileParser fileParser(testName);
    auto[graph, plan] = fileParser.parse();

    graph.DIJKSTRA(plan.getDestination());

    while (true) {

    }

//    std::ifstream file;

//    file.open(testsDir + "\\" + testName);
//    if (file.is_open()) {
//        std::string line;
//        while (getline (file,line)) {
//            std::cout << line << std::endl;
//        }
//    }
//
//    file.close();

    return 0;
}