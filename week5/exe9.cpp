#include <iostream>
#include <climits> 
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

    int maxPathSumUtil(Node* node, int& globalMax) {
        if (node == NULL) return 0;

        int leftSum = max(0, maxPathSumUtil(node->left, globalMax));
        int rightSum = max(0, maxPathSumUtil(node->right, globalMax));

        int localMax = leftSum + rightSum + node->data;
        globalMax = max(globalMax, localMax);

        return max(leftSum, rightSum) + node->data;
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

    int findMaxPathSum() {
        int globalMax = INT_MIN;
        maxPathSumUtil(root, globalMax);
        return globalMax;
    }
};

int main() {
    Tree tree;

    tree.insert(10);
    tree.insert(2);
    tree.insert(10);
    tree.insert(20);
    tree.insert(1);
    tree.insert(-25);
    tree.insert(3);
    tree.insert(4);

    cout << "Maximum Path Sum: " << tree.findMaxPathSum() << endl;

    return 0;
}
