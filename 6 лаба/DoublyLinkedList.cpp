#include "DoublyLinkedList.h"

DoublyLinkedList::DoublyLinkedList() : head(nullptr) {}

void DoublyLinkedList::Add(int value) {
    if (!head) {
        head = new Node(value);
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new Node(value);
        temp->next->prev = temp;
    }
}

void DoublyLinkedList::Print() const {
    Node* temp = head;
    while (temp) {
        std::cout << temp->data << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}
