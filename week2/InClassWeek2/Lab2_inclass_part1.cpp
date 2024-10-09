// STT: 22520585
// Full Name: Võ Hà Minh Huy
// In-Class-Exercise-Lap2-Part 1
// Notes or Remarks: ......
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

class Stack
{
private:
    Node *top;
    int size;
    int capacity;

public:
    Stack(int cap)
    {
        top = nullptr;
        size = 0;
        capacity = cap;
    }

    // Function to initialize (reset) the stack
    void initialize()
    {
        while (top != nullptr)
        {
            Node *temp = top;
            top = top->next;
            delete temp;
        }
        size = 0;
        cout << "Stack has been initialized (emptied).\n";
    }

    // Function to check if the stack is empty
    bool isEmpty()
    {
        return top == nullptr;
    }

    // Function to check if the stack is full
    bool isFull()
    {
        return size == capacity;
    }

    // Function to push an element onto the stack
    void push(int value)
    {
        if (isFull())
        {
            cout << "Stack overflow! Cannot push " << value << ". Stack is full.\n";
            return;
        }

        Node *newNode = new Node();
        if (!newNode)
        {
            cout << "Heap overflow! Unable to allocate memory.\n";
            return;
        }
        newNode->data = value;
        newNode->next = top;
        top = newNode;
        size++;
        cout << value << " pushed to stack.\n";
    }

    // Function to pop an element from the stack
    void pop()
    {
        if (isEmpty())
        {
            cout << "Stack underflow! No elements to pop.\n";
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << "Popped element: " << temp->data << "\n";
        delete temp;
        size--;
    }

    // Function to print the top element of the stack
    void printTop()
    {
        if (isEmpty())
        {
            cout << "Stack is empty.\n";
        }
        else
        {
            cout << "Top element: " << top->data << "\n";
        }
    }

    // Function to return the current size of the stack
    int getSize()
    {
        return size;
    }

    // Function to return the maximum capacity of the stack
    int getCapacity()
    {
        return capacity;
    }
};

// Main function to display the menu and interact with the stack
int main()
{
    cout << "STT: 22520585\n";
    cout << "Full Name : Vo Ha Minh Huy\n";
    cout << "In-Class-Exercise-Lap2-Part1\n";
    cout << "Notes or Remarks: ......\n";
    cout << "\n";

    int stackCapacity;
    cout << "Enter the capacity of the stack: ";
    cin >> stackCapacity;

    Stack stack(stackCapacity); // Initialize the stack with the given capacity

    int choice, value;

    do
    {
        cout << "\nStack Operations Menu:\n";
        cout << "1. Initialize the Stack\n";
        cout << "2. Check if Stack is Empty\n";
        cout << "3. Check if Stack is Full\n";
        cout << "4. Push an Element onto the Stack\n";
        cout << "5. Pop an Element from the Stack\n";
        cout << "6. Print the TOP element of the Stack\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1: // Initialize the stack
            stack.initialize();
            break;

        case 2: // Check if stack is empty
            if (stack.isEmpty())
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;

        case 3: // Check if stack is full
            if (stack.isFull())
            {
                cout << "Stack is full.\n";
            }
            else
            {
                cout << "Stack is not full.\n";
            }
            break;

        case 4: // Push an element onto the stack
            cout << "Enter value to push: ";
            cin >> value;
            stack.push(value);
            break;

        case 5: // Pop an element from the stack
            stack.pop();
            break;

        case 6: // Print the TOP element
            stack.printTop();
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