#pragma once

#include "graph.hpp"

std::vector<std::string> split(std::string data, const char c) {
    std::vector<std::string> returnData;
    std::string part = "";
    for (char i : data) {
        if (i == c) {
            returnData.push_back(part);
            part = "";
        } else {
            part += i;
        }
    }
    returnData.push_back(part);
    return returnData;
}

class FileParser {
    std::ifstream file;

    std::string current_working_directory() {
        char* cwd = _getcwd( 0, 0 ) ; // **** microsoft specific ****
        std::string working_directory(cwd) ;
        std::free(cwd) ;
        return working_directory ;
    }

    enum class FileLines {
        D_DESTINATION = 0,
        S_COLLECTION = 1,
        EDGE = 2,
        END,
        ERROR,
        NONE
    };

    FileLines readingState = FileLines::NONE;

public:
    FileParser(std::string fileName) {
        std::string pwd = current_working_directory();
        std::string testsFilePath;
        for(unsigned int i = pwd.length()-1; i> 0; i--) {
            if (pwd.at(i) == '\\') {
                testsFilePath = pwd.substr(0, i) + "\\tests";
                break;
            }
        }

        testsFilePath += "\\" + fileName;
        file.open(testsFilePath);

        if (file.good()) {
            std::cout << "Successfully opened file " << fileName << std::endl;
        } else {
            std::cout << "Can't open file " << fileName << " or it doesn't exist." << std::endl;
            std::exit(1);
        }

        readingState = FileLines::D_DESTINATION;
    }

    void parse() {
        Graph graph;

        if (file.is_open()) {
            std::string line;
            while (getline (file,line)) {
                std::size_t found;
                if (readingState == FileLines::D_DESTINATION) {
                    found = line.find_first_of("D=");
                    if (found!=std::string::npos) {
                        line = line.substr(3);
                        int destination = std::stoi(line);
                        graph.setDestination(destination);

//                        std::cout << "destination: " << destination << std::endl;

                        readingState = FileLines::S_COLLECTION;
                    } else {
                        readingState = FileLines::ERROR;
                    }
                } else if (readingState == FileLines::S_COLLECTION) {
                    found = line.find_first_of("S=");
                    if (found!=std::string::npos) {
                        line = line.substr(3);

                        auto ddd = split(line, ' ');

                        for(auto d: ddd) {
                            graph.addStartPoint(std::stoi(d));
                        }
//                        std::cout << "Start: " << line << std::endl;
                        readingState = FileLines::EDGE;
                    } else {
                        readingState = FileLines::ERROR;
                    }
                } else if (readingState == FileLines::EDGE) {
                    auto ddd = split(line, ' ');
                    graph.addEdge(Edge(std::stoi(ddd.at(0)), std::stoi(ddd.at(1))));
                }
            }
        }
    }

    ~FileParser () {
        file.close();
    }


};