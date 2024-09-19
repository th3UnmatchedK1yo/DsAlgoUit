
//Session 01 - Exercise 01
#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = nullptr;
    }
};

// Linked list class
class LinkedList {
public:
    Node* head;

    LinkedList() {
        head = nullptr;
    }

    // Function to add a new node to the linked list
    void add(int data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to find the middle of the linked list (for even length, print two middle nodes)
    void findMiddle() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* slow = head;
        Node* fast = head;
        Node* prevSlow = nullptr;  // To keep track of the previous slow node

        while (fast != nullptr && fast->next != nullptr) {
            prevSlow = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // If the fast pointer is not null, the list has an odd number of nodes
        if (fast == nullptr) {
            // Even number of nodes (output two middle nodes)
            cout << "The middle nodes are: " << prevSlow->data << " and " << slow->data << endl;
        } else {
            // Odd number of nodes (output only one middle node)
            cout << "The middle node is: " << slow->data << endl;
        }
    }

    // Function to display the linked list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

int main() {
    LinkedList list;

    // Adding nodes to the linked list
    list.add(1);
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);
    list.add(6);

    // Display the linked list
    cout << "Linked List: ";
    list.display();

    // Finding the middle node(s)
    list.findMiddle();

    return 0;
}

