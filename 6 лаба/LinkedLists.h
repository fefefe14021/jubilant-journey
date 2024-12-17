#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <iostream>

// Шаблонный класс для однонаправленного списка
template <typename T>
class SinglyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}
    void Add(T value);
    void Print() const;
    void RemoveDuplicates();
};

// Шаблонный класс для двунаправленного списка
template <typename T>
class DoublyLinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}
    void Add(T value);
    void Print() const;
};

#include "LinkedLists.inl" // Включение реализаций шаблонов
#endif
