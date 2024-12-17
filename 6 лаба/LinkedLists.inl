// SinglyLinkedList методы
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

// DoublyLinkedList методы
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
