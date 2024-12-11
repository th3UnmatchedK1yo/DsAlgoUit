#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val): data(val), left(NULL), right(NULL) {}
};

class Tree {
private:
    Node* root;

    // Recursive helper for inserting a node
    Node* insertNode(Node* root, int val) {
        if (root == NULL) {
            Node* newnode = new Node(val);
            return newnode;
        }
        if (val < root->data) {
            root->left = insertNode(root->left, val);
        } else {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

    // Recursive helper for deleting a node
    Node* deleteNode(Node* root, int val) {
        if (root == NULL) {
            return root;
        }

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {
            if (root->left == NULL && root->right == NULL) {
                delete root;
                return NULL;
            }
            if (root->left == NULL) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == NULL) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }

    // Helper to find the node with the minimum value
    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    // Traversal Helpers
    void preOrder(Node* root) {
        if (root == NULL) return;
        cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }

    void inOrder(Node* root) {
        if (root == NULL) return;
        inOrder(root->left);
        cout << root->data << " ";
        inOrder(root->right);
    }

    void postOrder(Node* root) {
        if (root == NULL) return;
        postOrder(root->left);
        postOrder(root->right);
        cout << root->data << " ";
    }

    void levelOrder(Node* root) {
        if (root == NULL) return;

        queue<Node*> q;
        q.push(root);

        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }

public:
    Tree(): root(NULL) {}

    void insert(int val) {
        root = insertNode(root, val);
    }

    void remove(int val) {
        root = deleteNode(root, val);
    }

    void displayPreOrder() {
        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }

    void displayInOrder() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }

    void displayPostOrder() {
        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }

    void displayLevelOrder() {
        cout << "Level-order Traversal: ";
        levelOrder(root);
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

    cout << "Binary Tree Traversals:" << endl;
    tree.displayPreOrder();     
    tree.displayInOrder();      
    tree.displayPostOrder();    
    tree.displayLevelOrder();   



    return 0;
}
