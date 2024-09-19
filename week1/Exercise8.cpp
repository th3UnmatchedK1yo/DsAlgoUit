
//Session 01 - Exercise 08

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

Node* search(Node* head, int x) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == x) {
            return current;  // Return the node if found
        }
        current = current->next;
    }
    return nullptr;  // Return nullptr if not found
}

void printList(Node* head) {
    while (head != nullptr) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    int searchValue;
    cout << "Enter a value to search in the linked list: ";
    cin >> searchValue;

    Node* result = search(head, searchValue);

    if (result != nullptr) {
        cout << "Node with value " << searchValue << " found at address: " << result << endl;
    } else {
        cout << "Node with value " << searchValue << " not found." << endl;
    }

    return 0;
}
