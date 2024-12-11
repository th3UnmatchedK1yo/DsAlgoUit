#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Tree {
public:

    Node* findLCA(Node* root, int node1, int node2) {
        if (root == NULL) {
            return NULL;
        }

        if (root->data == node1 || root->data == node2) {
            return root;
        }


        Node* leftLCA = findLCA(root->left, node1, node2);
        Node* rightLCA = findLCA(root->right, node1, node2);

        if (leftLCA != NULL && rightLCA != NULL) {
            return root;
        }

        return (leftLCA != NULL) ? leftLCA : rightLCA;
    }

    Node* insert(Node* root, int val) {
        if (root == NULL) {
            return new Node(val);
        }
        if (val < root->data) {
            root->left = insert(root->left, val);
        } else {
            root->right = insert(root->right, val);
        }
        return root;
    }

    void inorderTraversal(Node* root) {
        if (root == NULL) return;
        inorderTraversal(root->left);
        cout << root->data << " ";
        inorderTraversal(root->right);
    }
};

int main() {
    Tree tree;
    Node* root = NULL;

    root = tree.insert(root, 20);
    tree.insert(root, 10);
    tree.insert(root, 30);
    tree.insert(root, 5);
    tree.insert(root, 15);
    tree.insert(root, 25);
    tree.insert(root, 35);

    cout << "Inorder Traversal: ";
    tree.inorderTraversal(root);
    cout << endl;


    int node1 = 5, node2 = 15;
    Node* lca = tree.findLCA(root, node1, node2);
    if (lca != NULL) {
        cout << "LCA of " << node1 << " and " << node2 << " is: " << lca->data << endl;
    } else {
        cout << "LCA not found." << endl;
    }

    return 0;
}
