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
            Node* newnode = new Node(val);
            root = newnode;
            return root;
        }
        if (val < root->data) {
            root->left = insertNode(root->left, val);
        } else {
            root->right = insertNode(root->right, val);
        }
        return root;
    }

    Node* findMin(Node* root) {
        while (root->left != NULL) {
            root = root->left;
        }
        return root;
    }

    Node* deleteNode(Node* root, int val) {
        if (root == NULL) {
            return root;
        }

        if (val < root->data) {
            root->left = deleteNode(root->left, val);
        } else if (val > root->data) {
            root->right = deleteNode(root->right, val);
        } else {

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

    bool searchNode (Node* root, int val){
        if (root == NULL) {
            return false;
        }
        if(root->data==val){
            return true;
        }
        if (val < root->data) {
            searchNode(root->left, val);
        } else if (val > root->data) {
            searchNode(root->right, val);
        }
    }



public:
    Tree() : root(NULL) {}

    void insert(int val) {
        root = insertNode(root, val);
    }

    void remove(int val) {
        root = deleteNode(root, val);
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

    tree.remove(50);

    cout << "Inorder traversal after deleting 50: ";
    tree.printInorder();

    return 0;
}
