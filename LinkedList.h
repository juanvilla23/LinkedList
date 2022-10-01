//
// Created by srestrep74 on 28/09/22.
//

#ifndef UNTITLED_LINKEDLIST_H
#define UNTITLED_LINKEDLIST_H
#include<iostream>
#include "Node.h"

class LinkedList {
    public:
        Node *head;
        LinkedList();
        void insert(int value);
        void printList();
        void searchElement(int posicion);
        void pop(int posicion);
        int evenAverage();
        int oddAverage();
        void lower();
        void higher();
        void showRepeated();
        void sort();
        Node* mergeSort(Node *head);
        Node* merge(Node *list1, Node *list2);
        Node* getMid(Node *head);
        void reverse();
        void deleteRepeated();
        int len();
        bool isEmpty();
};


#endif //UNTITLED_LINKEDLIST_H
