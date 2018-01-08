#ifndef LIST_HPP
#define LIST_HPP

#include <iostream>
#include <vector>

namespace ads {

template<typename T>
class List {
    struct Node {
        T data;
        Node* next;
    };

    size_t list_size;

    Node* head;
public:
    List();
    ~List();

    size_t size();

    void insert(const T data);

    void reverse();

    template<typename U>
    friend std::ostream& operator<<(std::ostream& os, const List<U>& list);
};

template<typename T>
List<T>::List() : list_size(0), head(nullptr) { }

template<typename T>
List<T>::~List() {
    if (this->head != nullptr) {
        auto current = this->head;
        Node* next;

        while (current != nullptr) {
            next = current->next;
            delete current;
            current = next;
        }
        
        delete(current);
    }
}

template<typename T>
size_t List<T>::size() {
    return this->list_size;
}

template<typename T>
void List<T>::insert(const T data) {
    auto node = new Node{data, nullptr};

    if (this->head == nullptr) {
        this->head = node;
    } else {
        auto current = this->head;
        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = node;
    }

    this->list_size++;
}

template<typename T>
void List<T>::reverse() {
    if (this->list_size < 2) {
        return;
    }

    Node* prev = nullptr;
    auto current = this->head;
    Node* next;

    do {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    } while (current != nullptr);

    this->head = prev;
}

template<typename T>
void remove_loop(List<T>& list) {
    std::vector<Node*> seen_nodes;

    if (list.head.next == list.head) {
        list.head.next = nullptr;
    } else {
        auto curr_node = list.head;
        auto next_node = curr_node.next;
        seen_nodes.push_back(curr_node);

        while (next_node != nullptr) {
            if (seen_nodes.find(next_node) != seen_nodes.last()) {
                curr_node.next = nullptr;
            } else {
                seen_nodes.push_back(next_node);
                curr_node = next_node;
                next_node = curr_node.next;
            }
        }
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
