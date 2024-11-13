//22520585
//Vo Ha Minh Huy
//ex4

#include <iostream>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

class LinkedList {
public:
    Node* head;

    LinkedList() : head(NULL) {}

    void append(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void bubbleSort() {
        if (!head) return;
        bool swapped;
        do {
            swapped = false;
            Node* curr = head;
            while (curr && curr->next) {
                if (curr->data > curr->next->data) {
                    swap(curr->data, curr->next->data);
                    swapped = true;
                }
                curr = curr->next;
            }
        } while (swapped);
    }

    void print() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

long long measureSortTime(void (LinkedList::*sortFunc)(), LinkedList& container, const string& sortName) {
    clock_t start = clock();
    (container.*sortFunc)();
    clock_t end = clock();
    double duration = double(end - start) / CLOCKS_PER_SEC * 1000000; // Convert to microseconds
    cout << sortName << " time: " << duration << " microseconds" << endl;
    return duration;
}

int main() {
    int n = 10; // Test with 10 elements

    LinkedList linkedList;
    cout << "Enter 10 numbers to add to the linked list:" << endl;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        linkedList.append(value);
    }

    cout << "Before sorting:" << endl;
    linkedList.print();

    measureSortTime(&LinkedList::bubbleSort, linkedList, "Bubble Sort");

    cout << "After sorting:" << endl;
    linkedList.print();

    return 0;
}
