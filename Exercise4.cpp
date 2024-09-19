
//Session 01 - Exercise 04

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

int getLength(Node* head) {
    int length = 0;
    while (head != nullptr) {
        length++;
        head = head->next;
    }
    return length;
}

Node* findIntersection(Node* head1, Node* head2) {
    int len1 = getLength(head1);
    int len2 = getLength(head2);

    while (len1 > len2) {
        head1 = head1->next;
        len1--;
    }

    while (len2 > len1) {
        head2 = head2->next;
        len2--;
    }

    while (head1 != nullptr && head2 != nullptr) {
        if (head1 == head2) {
            return head1;
        }
        head1 = head1->next;
        head2 = head2->next;
    }

    return nullptr;  // No intersection
}

int main() {
    Node* common = new Node(7);
    common->next = new Node(8);
    common->next->next = new Node(9);

    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = common;

    Node* head2 = new Node(3);
    head2->next = new Node(4);
    head2->next->next = new Node(5);
    head2->next->next->next = common;

    Node* intersection = findIntersection(head1, head2);

    if (intersection) {
        cout << "The lists intersect at node with data: " << intersection->data << endl;
    } else {
        cout << "The lists do not intersect." << endl;
    }

    return 0;
}
