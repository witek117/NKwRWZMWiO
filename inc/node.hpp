#pragma once

#include <vector>

class Node {
    int indexNumber;
    std::vector<int> friends;

public:
    Node(int indexNumber) : indexNumber(indexNumber) { }

    void addFriend(int friendIndex) {
        friends.push_back(friendIndex);
    }

    int getIndex() {
        return indexNumber;
    }
};