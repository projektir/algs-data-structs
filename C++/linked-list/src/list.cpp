#include "list.hpp"

using ads::List;

List::List() {
    this->head = nullptr;
}

List::~List() {
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

void List::insert(const int data) {
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

std::ostream& ads::operator<<(std::ostream& stream, const List& list)
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
