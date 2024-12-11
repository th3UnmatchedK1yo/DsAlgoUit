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
    int height(Node* root) {
        if (root == NULL) return -1; 

        return 1 + max(height(root->left), height(root->right));
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

    int getHeight() {
        return height(root);
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

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    cout << "Inorder traversal: ";
    tree.printInorder(); 

    cout << "Height of the tree: " << tree.getHeight() << endl; 

    return 0;
}
