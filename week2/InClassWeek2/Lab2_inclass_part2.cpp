// STT: 22520585
// Full Name: Võ Hà Minh Huy
// In-Class-Exercise-Lap2-Part2
// Notes or Remarks: ......
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;
    int size;
    int capacity;

public:
    Queue(int cap)
    {
        front = rear = nullptr;
        size = 0;
        capacity = cap;
    }

    // Function to initialize (reset) the queue
    void initialize()
    {
        while (front != nullptr)
        {
            Node *temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
        size = 0;
        cout << "Queue has been initialized (emptied).\n";
    }

    bool isEmpty()
    {
        return front == nullptr;
    }

    bool isFull()
    {
        return size == capacity;
    }

    // Function to enqueue an element into the queue
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "Queue overflow! Cannot enqueue " << value << ". Queue is full.\n";
            return;
        }

        Node *newNode = new Node(); //
        if (!newNode)
        {
            cout << "Heap overflow! Unable to allocate memory.\n";
            return;
        }
        newNode->data = value;
        newNode->next = nullptr;

        if (rear == nullptr)
        {
            front = rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
        size++;
        cout << value << " enqueued to queue.\n";
    }

    // Function to dequeue an element from the queue
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow! No elements to dequeue.\n";
            return;
        }

        Node *temp = front;
        front = front->next;

        if (front == nullptr)
        {
            rear = nullptr;
        }

        cout << "Dequeued element: " << temp->data << "\n";
        delete temp;
        size--;
    }

    // Function to print the front and rear elements of the queue
    void printFrontAndRear()
    {
        if (isEmpty())
        {
            cout << "Queue is empty.\n";
        }
        else
        {
            cout << "Front element: " << front->data << "\n";
            cout << "Rear element: " << rear->data << "\n";
        }
    }

    // Function to return the current size of the queue
    int getSize()
    {
        return size;
    }

    // Function to return the maximum capacity of the queue
    int getCapacity()
    {
        return capacity;
    }
};

int main()
{
    cout << "STT: 22520585\n";
    cout << "Full Name : Vo Ha Minh Huy\n";
    cout << "In-Class-Exercise-Lap2-Part2\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";
    int queueCapacity;
    cout << "Enter the capacity of the queue: ";
    cin >> queueCapacity;

    Queue queue(queueCapacity);

    int choice, value;

    do
    {
        cout << "\nQueue Operations Menu:\n";
        cout << "1. Initialize the Queue\n";
        cout << "2. Check if Queue is Empty\n";
        cout << "3. Check if Queue is Full\n";
        cout << "4. Enqueue an Element into the Queue\n";
        cout << "5. Dequeue an Element from the Queue\n";
        cout << "6. Print the FRONT and REAR elements of the Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Initialize the queue
            queue.initialize();
            break;

        case 2: // Check if queue is empty
            if (queue.isEmpty())
            {
                cout << "Queue is empty.\n";
            }
            else
            {
                cout << "Queue is not empty.\n";
            }
            break;

        case 3: // Check if queue is full
            if (queue.isFull())
            {
                cout << "Queue is full.\n";
            }
            else
            {
                cout << "Queue is not full.\n";
            }
            break;

        case 4: // Enqueue an element into the queue
            cout << "Enter value to enqueue: ";
            cin >> value;
            queue.enqueue(value);
            break;

        case 5: // Dequeue an element from the queue
            queue.dequeue();
            break;

        case 6: // Print the FRONT and REAR elements
            queue.printFrontAndRear();
            break;

        case 7: // Exit
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 7);

    return 0;
}