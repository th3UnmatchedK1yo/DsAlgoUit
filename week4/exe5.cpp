//22520585
//Vo Ha Minh Huy
//ex5
#include <iostream>
#include <cstdlib>
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

    Node* binarySearch(Node* start, int value) {
        Node* end = NULL;
        while (start != end) {
            Node* mid = start;
            Node* fast = start;

            while (fast != end && fast->next != end) {
                fast = fast->next->next;
                mid = mid->next;
            }

            if (mid->data > value) {
                end = mid;
            } else {
                start = mid->next;
            }
        }
        return start;
    }

    void insertionSort() {
        if (!head || !head->next) return;

        Node* sorted = NULL;
        Node* curr = head;
        while (curr) {
            Node* next = curr->next;
            Node* position = binarySearch(sorted, curr->data);

            if (!sorted || position == sorted) {
                curr->next = sorted;
                sorted = curr;
            } else {
                Node* temp = sorted;
                while (temp->next != position) {
                    temp = temp->next;
                }
                temp->next = curr;
                curr->next = position;
            }
            curr = next;
        }
        head = sorted;
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
    long long duration = (end - start) * 1000000 / CLOCKS_PER_SEC;  // Đo thời gian tính bằng microseconds
    cout << sortName << " time: " << duration << " microseconds" << endl;
    return duration;
}

int main() {
    srand(time(0));

    int n = 100;

    LinkedList linkedList;
    for (int i = 0; i < n; ++i) {
        linkedList.append(rand() % 10000);
    }

    cout << "Sorting Linked List with Binary Search Insertion Sort:" << endl;
    measureSortTime(&LinkedList::insertionSort, linkedList, "Binary Search Insertion Sort");

    return 0;
}
