#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> canSeePersonsCount(vector<int> &heights)
{
    int n = heights.size();
    vector<int> answer(n, 0);
    stack<int> st; // Stack to track visible heights

    // Traverse from right to left
    for (int i = n - 1; i >= 0; --i)
    {
        int count = 0;
        // Count people that the current person `i` can see directly
        while (!st.empty() && st.top() < heights[i])
        {
            st.pop();
            count++;
        }
        // If there's someone taller or equal to the current, they also block the view
        if (!st.empty())
        {
            count++;
        }

        answer[i] = count;
        st.push(heights[i]); // Push the current height onto the stack
    }

    return answer;
}

int main()
{
    int n;
    cout << "Enter the number of people: ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights of the people: ";
    for (int i = 0; i < n; ++i)
    {
        cin >> heights[i];
    }

    vector<int> result = canSeePersonsCount(heights);

    cout << "The number of people each person can see to their right: ";
    for (int count : result)
    {
        cout << count << " ";
    }
    cout << endl;

    return 0;
}
