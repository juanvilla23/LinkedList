//
// Created by srestrep74 on 28/09/22.
//
#include<iostream>
#include "Node.h"
using namespace std;

Node::Node() {
    this->value = NULL;
    this->next = NULL;

}
Node::Node(int value){
    this->value = value;
    this->next = NULL;
}

Node::Node(int value, Node *next){
    this->value = value;
    this->next = next;
}
