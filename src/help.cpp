#include "help.hpp"
#include <iostream>

void printHelp() {
    std::cout << "Usage: TASK12 [FILE_NAME]" << std::endl;
    std::cout << "Calculate shortest path to destination from given start points, given input in [FILE]." << std::endl << std::endl;

    std::cout << "With no FILE, default input file name is test1.txt" << std::endl;

    std::cout << "Description of file contents:" << std::endl;
    std::cout << "The first row of an input file: destination node name (index)" << std::endl;
    std::cout << "The second row of an input file: source nodes names (indexes)" << std::endl;

    std::cout << "Rest rows of an input file - edges description: start index, stop index" << std::endl;

    std::cout << "For example:" << std::endl;
    std::cout << "D= 11" << std::endl;
    std::cout << "S= 1 2 3 4" << std::endl;
    std::cout << "1 5" << std::endl;
    std::cout << "2 6" << std::endl;
    std::cout << "3 6" << std::endl;
    std::cout << "4 7" << std::endl;
    std::cout << "5 9" << std::endl;
    std::cout << "6 9" << std::endl;
    std::cout << "7 10" << std::endl;
    std::cout << "7 8" << std::endl;
    std::cout << "8 12" << std::endl;
    std::cout << "9 12" << std::endl;
    std::cout << "11 12" << std::endl;
    std::cout << "11 10" << std::endl;


    std::cout << "Is equivalent to graph:" << std::endl;

//    std::cout << " 0 ----t=1---- 1 ----t=1---- 4" << std::endl;
//    std::cout << " |             |" << std::endl;
//    std::cout << " |             |" << std::endl;
//    std::cout << "t=3           t=1" << std::endl;
//    std::cout << " |             |" << std::endl;
//    std::cout << " |             |" << std::endl;
//    std::cout << " 3 ----t=2---- 2" << std::endl;
//    std::cout << "With maximum time of 4." << std::endl;
}


void printHelpAndExit(int exit_code) {
    printHelp();
    std::exit(exit_code);
}