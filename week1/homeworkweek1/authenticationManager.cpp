#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

// AuthenticationManager Class Implementation
class AuthenticationManager
{
private:
    int timeToLive;
    unordered_map<string, int> tokens; // Maps tokenId to its expiration time

public:
    // Constructor initializes the timeToLive
    AuthenticationManager(int timeToLive)
    {
        this->timeToLive = timeToLive;
    }

    // Generates a new token with the given tokenId at currentTime
    void generate(string tokenId, int currentTime)
    {
        tokens[tokenId] = currentTime + timeToLive;
    }

    // Renews the token if it is unexpired at currentTime
    void renew(string tokenId, int currentTime)
    {
        auto it = tokens.find(tokenId);
        if (it != tokens.end() && it->second > currentTime)
        {
            // Token is unexpired, renew it
            tokens[tokenId] = currentTime + timeToLive;
        }
        // If token is expired or does not exist, do nothing
    }

    // Counts the number of unexpired tokens at currentTime
    int countUnexpiredTokens(int currentTime)
    {
        // Remove expired tokens
        vector<string> expiredTokens;
        for (const auto &token : tokens)
        {
            if (token.second <= currentTime)
            {
                expiredTokens.push_back(token.first);
            }
        }
        for (const auto &tokenId : expiredTokens)
        {
            tokens.erase(tokenId);
        }

        // Return the count of unexpired tokens
        return tokens.size();
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
    // Read input for AuthenticationManager
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
    AuthenticationManager *manager = nullptr;

    for (size_t i = 0; i < operations.size(); ++i)
    {
        string op = operations[i];
        vector<string> &args = arguments[i];

        if (op == "AuthenticationManager")
        {
            int timeToLive = stoi(args[0]);
            manager = new AuthenticationManager(timeToLive);
            outputs.push_back("null");
        }
        else if (op == "generate")
        {
            manager->generate(args[0], stoi(args[1]));
            outputs.push_back("null");
        }
        else if (op == "renew")
        {
            manager->renew(args[0], stoi(args[1]));
            outputs.push_back("null");
        }
        else if (op == "countUnexpiredTokens")
        {
            int count = manager->countUnexpiredTokens(stoi(args[0]));
            outputs.push_back(to_string(count));
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
    if (manager)
        delete manager;

    return 0;
}
