
//Session 01 - Exercise 02 

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

bool detectCycle(Node* head) {
    Node* slow = head;
    Node* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            return true;  // Cycle detected
        }
    }
    return false;  // No cycle
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = head->next;  // Creates a cycle

    if (detectCycle(head)) {
        cout << "Cycle detected in the linked list." << endl;
    } else {
        cout << "No cycle detected in the linked list." << endl;
    }

    return 0;
}
