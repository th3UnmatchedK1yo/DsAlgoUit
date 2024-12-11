#include <iostream>
#include <algorithm> // For std::max
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


    int checkHeightBalance(Node* root, bool& isBalanced) {
        if (root == NULL) return 0; 

        int leftHeight = checkHeightBalance(root->left, isBalanced);
        int rightHeight = checkHeightBalance(root->right, isBalanced);

        if (abs(leftHeight - rightHeight) > 1) {
            isBalanced = false; 
        }

        return 1 + max(leftHeight, rightHeight); 
    }

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

    bool isBalanced() {
        bool isBalancedTree = true;
        checkHeightBalance(root, isBalancedTree);
        return isBalancedTree;
    }
};

int main() {
    Tree tree;

    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(2);
    tree.insert(8);

    if (tree.isBalanced()) {
        cout << "The tree is height-balanced." << endl;
    } else {
        cout << "The tree is not height-balanced." << endl;
    }

    return 0;
}
