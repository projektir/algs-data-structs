#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>

namespace ads {

template<typename T>
class List {
    struct Node {
        int data;
        Node* next;
    };

    Node* head;
public:
    List();
    ~List();

    void insert(const int data);

    template<typename T>
    friend std::ostream& operator<<(std::ostream& os, const List<T>& list);
};

template<typename T>
List<T>::List() {
    this->head = nullptr;
}

template<typename T>
List<T>::~List() {
    if (this->head != nullptr) {
        auto current = this->head;
        auto next = current;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        
        delete(current);
    }
}

template<typename T>
void List<T>::insert(const int data) {
    auto node = new Node{data, nullptr};

    if (this->head == nullptr) {
        this->head = node;
    } else {
        auto current_node = this->head;
        while (current_node->next != nullptr) {
            current_node = current_node->next;
        }

        current_node->next = node;
    }
}

template<typename T>
std::ostream& operator<<(std::ostream& stream, const List<T>& list)
{
    if (list.head == nullptr) {
        stream << "{ }";
    } else {
        stream << "{ " << list.head->data;

        auto node = list.head->next;

        while (node != nullptr) {
            stream << " }, " "{ " << node->data;
            node = node->next;
        }

        stream << " }";
    }

    return stream;
}

}

#endif /* LIST_HPP */
