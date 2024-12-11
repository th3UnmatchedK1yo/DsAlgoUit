#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
private:
    Node* root;

public:
    Tree() : root(NULL) {}

    void insert(int val) {
        root = insertNode(root, val);
    }

    Node* insertNode(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insertNode(root->left, val);
        } else {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

    vector<vector<int>> levelOrderTraversal() {
        vector<vector<int>> result;
        if (root == NULL) return result;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> currentLevel;

            for (int i = 0; i < levelSize; i++) {
                Node* current = q.front();
                q.pop();
                currentLevel.push_back(current->data);

                if (current->left) q.push(current->left);
                if (current->right) q.push(current->right);
            }
            result.push_back(currentLevel);
        }

        return result;
    }

    void printLevelOrder() {
        vector<vector<int>> levels = levelOrderTraversal();
        for (int i = 0; i < levels.size(); i++) {
            cout << "Level " << i + 1 << ": ";
            for (int val : levels[i]) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Tree tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Level-order traversal (by levels):" << endl;
    tree.printLevelOrder();

    return 0;
}
