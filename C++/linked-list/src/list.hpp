#include <iostream>

namespace ads {

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

    friend std::ostream& operator<<(std::ostream& os, const List& list);
};

}
