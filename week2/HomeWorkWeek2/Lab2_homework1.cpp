#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Vector to store the steps for display
vector<string> steps;

// Function to display the state of the towers
void displayTowers(stack<int> A, stack<int> B, stack<int> C, int step)
{
    cout << "============= Demo Stack ===========" << endl;
    cout << step << ". Creating Tower" << endl;

    for (int i = 0; i < steps.size(); ++i)
    {
        cout << i + 1 << ". " << steps[i] << endl;
    }

    cout << "=====================================" << endl;
    cout << "A Tower\nSTACK = < ";
    vector<int> a_disks;
    while (!A.empty())
    {
        a_disks.push_back(A.top());
        A.pop();
    }
    for (auto it = a_disks.rbegin(); it != a_disks.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << ">" << endl;

    cout << "=====================================" << endl;
    cout << "B Tower\nSTACK = < ";
    vector<int> b_disks;
    while (!B.empty())
    {
        b_disks.push_back(B.top());
        B.pop();
    }
    for (auto it = b_disks.rbegin(); it != b_disks.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << ">" << endl;

    cout << "=====================================" << endl;
    cout << "C Tower\nSTACK = < ";
    vector<int> c_disks;
    while (!C.empty())
    {
        c_disks.push_back(C.top());
        C.pop();
    }
    for (auto it = c_disks.rbegin(); it != c_disks.rend(); ++it)
    {
        cout << *it << " ";
    }
    cout << ">" << endl;
    cout << "=====================================" << endl;
}

// Function to move disks and store the steps
void moveDisk(stack<int> &source, stack<int> &target, char s, char t)
{
    int disk = source.top();
    source.pop();
    target.push(disk);
    string move = s + string("->") + t;
    steps.push_back(move);
}

// Recursive function for Tower of Hanoi
void towerOfHanoi(int n, stack<int> &A, stack<int> &B, stack<int> &C, char source, char target, char auxiliary)
{
    if (n == 1)
    {
        moveDisk(A, C, source, target);
        return;
    }

    // Move n-1 disks from source to auxiliary using target as auxiliary
    towerOfHanoi(n - 1, A, C, B, source, auxiliary, target);
    // Move the nth disk from source to target
    moveDisk(A, C, source, target);
    // Move n-1 disks from auxiliary to target using source as auxiliary
    towerOfHanoi(n - 1, B, A, C, auxiliary, target, source);
}

int main()
{
    int n; // Number of disks
    cout << "Enter the number of disks: ";
    cin >> n;

    // Initialize towers as stacks
    stack<int> A, B, C;
    for (int i = n; i >= 1; --i)
    {
        A.push(i);
    }

    int step = 0;
    // A, B, and C are the names of the towers
    towerOfHanoi(n, A, B, C, 'A', 'C', 'B');

    // Display the final state with all steps at once
    displayTowers(A, B, C, step);

    return 0;
}
