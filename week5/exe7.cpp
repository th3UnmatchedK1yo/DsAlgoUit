#include <iostream>
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

    Node* findLCA(Node* root, int p, int q) {
        if (root == NULL) return NULL;

        if (p < root->data && q < root->data) {
            return findLCA(root->left, p, q);
        }


        if (p > root->data && q > root->data) {
            return findLCA(root->right, p, q);
        }

        return root;
    }

public:
    Tree() : root(NULL) {}

    void insert(int val) {
        root = insertNode(root, val);
    }

    Node* findLCA(int p, int q) {
        return findLCA(root, p, q);
    }

    void inorder(Node* root) {
        if (root == NULL) return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void printInorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    Tree tree;

    tree.insert(20);
    tree.insert(10);
    tree.insert(30);
    tree.insert(5);
    tree.insert(15);
    tree.insert(25);
    tree.insert(35);

    cout << "Inorder traversal: ";
    tree.printInorder();

    int p = 5, q = 15;
    Node* lca = tree.findLCA(p, q);
    if (lca) {
        cout << "Lowest Common Ancestor of " << p << " and " << q << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
