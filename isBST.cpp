#include <iostream>
#include <climits>
using namespace std;

// Define the structure for a binary tree node
template <typename T>
struct BinaryTreeNode {
    T data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(T val) : data(val), left(NULL), right(NULL) {}
};

// Helper function to validate the BST
bool solve(BinaryTreeNode<int> *root, int min, int max) {
    if (root == NULL) {
        return true;
    }
    if (root->data >= min && root->data <= max) {
        return solve(root->left, min, root->data) && solve(root->right, root->data, max);
    } else {
        return false;
    }    
}

// Main function to validate the BST
bool validateBST(BinaryTreeNode<int> *root) {
    return solve(root, INT_MIN, INT_MAX);
}

// Driver code to test the validateBST function
int main() {
    /* Constructed binary tree is
            4
          /   \
         2     5
        / \
       1   3
    */
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(4);
    root->left = new BinaryTreeNode<int>(2);
    root->right = new BinaryTreeNode<int>(5);
    root->left->left = new BinaryTreeNode<int>(1);
    root->left->right = new BinaryTreeNode<int>(3);

    if (validateBST(root)) {
        cout << "The binary tree is a valid BST." << endl;
    } else {
        cout << "The binary tree is not a valid BST." << endl;
    }

    return 0;
}
// TC-O(N)
// SC-O(H)
