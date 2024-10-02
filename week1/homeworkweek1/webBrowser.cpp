#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

// BrowserHistory Class Implementation
class BrowserHistory
{
private:
    vector<string> history;
    int current; // Index of the current page

public:
    // Constructor initializes the homepage
    BrowserHistory(string homepage)
    {
        history.push_back(homepage);
        current = 0;
    }

    // Visit a new URL from the current page
    void visit(string url)
    {
        // Discard forward history beyond the current page
        history.resize(current + 1);
        history.push_back(url);
        current++;
    }

    // Move back by 'steps' pages and return the current URL
    string back(int steps)
    {
        current = max(0, current - steps);
        return history[current];
    }

    // Move forward by 'steps' pages and return the current URL
    string forward(int steps)
    {
        current = min(static_cast<int>(history.size()) - 1, current + steps);
        return history[current];
    }
};

// Helper functions to parse input strings
vector<string> parseOperations(const string &ops_line)
{
    vector<string> operations;
    string op;
    bool in_quote = false;
    for (char ch : ops_line)
    {
        if (ch == '"')
        {
            in_quote = !in_quote;
            if (!in_quote && !op.empty())
            {
                operations.push_back(op);
                op.clear();
            }
        }
        else if (in_quote)
        {
            op += ch;
        }
    }
    return operations;
}

vector<vector<string>> parseArguments(const string &args_line)
{
    vector<vector<string>> arguments;
    vector<string> currentArgs;
    string arg;
    bool in_quote = false;
    for (size_t i = 0; i < args_line.size(); ++i)
    {
        char ch = args_line[i];
        if (ch == '"')
        {
            in_quote = !in_quote;
            if (!in_quote && !arg.empty())
            {
                currentArgs.push_back(arg);
                arg.clear();
            }
        }
        else if (in_quote)
        {
            arg += ch;
        }
        else if (ch == '[')
        {
            currentArgs.clear();
        }
        else if (ch == ']')
        {
            if (!currentArgs.empty())
            {
                arguments.push_back(currentArgs);
                currentArgs.clear();
            }
        }
        else if (isdigit(ch) || ch == '-')
        {
            // Parse numbers
            string num;
            while (i < args_line.size() && (isdigit(args_line[i]) || args_line[i] == '-'))
            {
                num += args_line[i];
                i++;
            }
            i--;
            currentArgs.push_back(num);
        }
    }
    return arguments;
}

int main()
{
    // Read input for BrowserHistory
    string ops_line, args_line;

    // Input: Operations
    getline(cin, ops_line);

    // Input: Arguments
    getline(cin, args_line);

    // Remove leading and trailing brackets
    if (ops_line.front() == '[' && ops_line.back() == ']')
    {
        ops_line = ops_line.substr(1, ops_line.size() - 2);
    }
    if (args_line.front() == '[' && args_line.back() == ']')
    {
        args_line = args_line.substr(1, args_line.size() - 2);
    }

    // Parse operations and arguments
    vector<string> operations = parseOperations(ops_line);
    vector<vector<string>> arguments = parseArguments(args_line);

    vector<string> outputs;
    BrowserHistory *browser = nullptr;

    for (size_t i = 0; i < operations.size(); ++i)
    {
        string op = operations[i];
        vector<string> &args = arguments[i];

        if (op == "BrowserHistory")
        {
            browser = new BrowserHistory(args[0]);
            outputs.push_back("null");
        }
        else if (op == "visit")
        {
            browser->visit(args[0]);
            outputs.push_back("null");
        }
        else if (op == "back")
        {
            int steps = stoi(args[0]);
            string res = browser->back(steps);
            outputs.push_back("\"" + res + "\"");
        }
        else if (op == "forward")
        {
            int steps = stoi(args[0]);
            string res = browser->forward(steps);
            outputs.push_back("\"" + res + "\"");
        }
    }

    // Output the results
    cout << "[";
    for (size_t i = 0; i < outputs.size(); ++i)
    {
        cout << outputs[i];
        if (i != outputs.size() - 1)
            cout << ", ";
    }
    cout << "]" << endl;

    // Clean up
    if (browser)
        delete browser;

    return 0;
}
