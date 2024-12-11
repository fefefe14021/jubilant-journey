#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H

#include <iostream>

class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList();
    void Add(int value);
    void RemoveDuplicates();
    void Print() const;
};

#endif
