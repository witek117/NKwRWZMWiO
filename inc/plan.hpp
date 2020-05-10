#pragma once

#include <vector>

class Plan {
    int destinationIndex = -1;
    std::vector<int> S_COLLECTION;
public:
    void setDestination(int nodeIndex) {
        destinationIndex = nodeIndex;
    }

    void addStartPoint(int index) {
        S_COLLECTION.push_back(index);
    }

    int getDestination() {
        return destinationIndex;
    }
};