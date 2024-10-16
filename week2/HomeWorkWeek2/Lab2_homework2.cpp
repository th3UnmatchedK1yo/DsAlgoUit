#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Browser
{
public:
    Browser() : currentUrl("") {}

    void visit(const string &url)
    {
        if (!currentUrl.empty())
        {
            backStack.push(currentUrl);
        }
        currentUrl = url;
        // Clear the forward stack because we cannot go forward after visiting a new page
        while (!forwardStack.empty())
        {
            forwardStack.pop();
        }
        cout << "Visited: " << currentUrl << endl;
    }

    string back()
    {
        if (backStack.empty())
        {
            cout << "No previous URL to go back to." << endl;
            return currentUrl;
        }
        forwardStack.push(currentUrl);
        currentUrl = backStack.top();
        backStack.pop();
        cout << "Back to: " << currentUrl << endl;
        return currentUrl;
    }

    string forward()
    {
        if (forwardStack.empty())
        {
            cout << "No next URL to go forward to." << endl;
            return currentUrl;
        }
        backStack.push(currentUrl);
        currentUrl = forwardStack.top();
        forwardStack.pop();
        cout << "Forward to: " << currentUrl << endl;
        return currentUrl;
    }

private:
    stack<string> backStack;
    stack<string> forwardStack;
    string currentUrl;
};

int main()
{
    Browser browser;
    browser.visit("http://httt.uit.edu.vn");
    browser.visit("http://uit.edu.vn");
    browser.back();    // Returns "http://httt.uit.edu.vn"
    browser.forward(); // Returns "http://uit.edu.vn"
    browser.visit("http://daa.uit.edu.vn");
    browser.back(); // Returns "http://uit.edu.vn"

    return 0;
}
