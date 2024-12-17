#ifndef LINKEDLISTS_H
#define LINKEDLISTS_H

#include <iostream>
#include <set>
#include <fstream>

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

// Реализация методов SinglyLinkedList
template <typename T>
void SinglyLinkedList<T>::Add(T value) {
    if (!head) {
        head = new Node(value);
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new Node(value);
    }
}

template <typename T>
void SinglyLinkedList<T>::Print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

template <typename T>
void SinglyLinkedList<T>::RemoveDuplicates() {
    if (!head) return;
    Node* current = head;
    while (current && current->next) {
        if (current->data == current->next->data) {
            Node* duplicate = current->next;
            current->next = duplicate->next;
            delete duplicate;
        } else {
            current = current->next;
        }
    }
}

// Реализация методов DoublyLinkedList
template <typename T>
void DoublyLinkedList<T>::Add(T value) {
    if (!head) {
        head = new Node(value);
    } else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = new Node(value);
        temp->next->prev = temp;
    }
}

template <typename T>
void DoublyLinkedList<T>::Print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

#endif // LINKEDLISTS_H
