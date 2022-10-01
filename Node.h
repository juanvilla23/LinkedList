//
// Created by srestrep74 on 28/09/22.
//

#ifndef UNTITLED_NODE_H
#define UNTITLED_NODE_H


class Node {
    public:
        int value;
        Node *next;
        Node();
        Node(int value);
        Node(int value, Node* next);
};


#endif //UNTITLED_NODE_H
