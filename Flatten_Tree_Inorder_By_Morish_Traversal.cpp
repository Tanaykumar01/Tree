#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    void flatten(Node *root) {
        if (root == NULL) {
            return;
        }
        Node* current = root;
        while (current != NULL) {
            if (current->left != NULL) {
                Node* pre = current->left;
                while (pre->right != NULL) {
                    pre = pre->right;
                }
                pre->right = current->right;
                current->right = current->left;
                current->left = NULL;
            }
            current = current->right;
        }
    }
};

void printFlattenedTree(Node* root) {
    while (root != NULL) {
        cout << root->data << " ";
        root = root->right;
    }
    cout << endl;
}

int main() {
    /* Constructed binary tree is
            1
          /   \
         2     5
        / \     \
       3   4     6
    */
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->right->right = new Node(6);

    Solution sol;
    sol.flatten(root);

    cout << "Flattened tree: ";
    printFlattenedTree(root);

    return 0;
}


// TC - O(N)
// SC - O(1)
