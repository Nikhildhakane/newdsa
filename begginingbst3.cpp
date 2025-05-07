/*Experiment No: 3 =Beginning with an empty binary search tree, Construct binary search tree by 
 inserting the values in the order given. After constructing a binary tree - i. Insert new node ii.
 Find number of nodes in longest path from root iii. Minimum data value found in the tree iv. 
 Change a tree so that the roles of the left and right pointers are swapped at every node v.
  Search a value*/


#include <iostream>
#include <algorithm>
using namespace std;

// Structure for a node in the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;

    // Constructor
    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Class for Binary Search Tree (BST) implementation
class BinarySearchTree {
private:
    Node* root;

    // Helper function to insert a node into the BST
    Node* insert(Node* node, int val) {
        if (node == NULL) {
            return new Node(val);
        }
        if (val < node->data) {
            node->left = insert(node->left, val);
        } else {
            node->right = insert(node->right, val);
        }
        return node;
    }

    // Helper function to find the height (number of nodes in the longest path) of the tree
    int height(Node* node) {
        if (node == NULL) return 0;
        int leftHeight = height(node->left);
        int rightHeight = height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }

    // Helper function to find the minimum data value in the tree
    Node* findMin(Node* node) {
        while (node && node->left != NULL) {
            node = node->left;
        }
        return node;
    }

    // Helper function to perform a search for a value
    bool search(Node* node, int val) {
        if (node == NULL) return false;
        if (val == node->data) return true;
        if (val < node->data) return search(node->left, val);
        return search(node->right, val);
    }

    // Helper function to swap left and right subtrees at every node
    void swapSubtrees(Node* node) {
        if (node == NULL) return;
        swap(node->left, node->right); // Swap left and right pointers
        swapSubtrees(node->left);      // Recursively swap left and right subtrees
        swapSubtrees(node->right);     // Recursively swap left and right subtrees
    }

public:
    // Constructor
    BinarySearchTree() {
        root = NULL;
    }

    // Function to insert a new node with the given value
    void insert(int val) {
        root = insert(root, val);
    }

    // Function to find the height of the tree (longest path from root)
    int findHeight() {
        return height(root);
    }

    // Function to find the minimum data value in the tree
    int findMinValue() {
        Node* minNode = findMin(root);
        if (minNode != NULL) return minNode->data;
        return -1; // If tree is empty, return -1
    }

    // Function to swap the left and right subtrees at every node
    void swapTree() {
        swapSubtrees(root);
    }

    // Function to search for a specific value in the tree
    bool searchValue(int val) {
        return search(root, val);
    }

    // Getter for root node
    Node* getRoot() {
        return root;
    }
};

// Standalone function for inorder traversal
void inorderTraversal(Node* node) {
    if (node == NULL) return;
    inorderTraversal(node->left);
    cout << node->data << " ";
    inorderTraversal(node->right);
}

// Main function
int main() {
    BinarySearchTree bst;

    // Insert values in the given order
    cout << "Inserting values into the BST: 50, 30, 20, 40, 70, 60, 80\n";
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);

    cout << "In-order traversal of the tree: ";
    inorderTraversal(bst.getRoot());
    cout << endl;

    // i. Insert a new node
    int newValue;
    cout << "Enter a value to insert: ";
    cin >> newValue;
    bst.insert(newValue);

    cout << "In-order traversal after insertion: ";
    inorderTraversal(bst.getRoot());
    cout << endl;

    // ii. Find number of nodes in the longest path (height of the tree)
    cout << "The number of nodes in the longest path (height) from the root: " << bst.findHeight() << endl;

    // iii. Find the minimum data value found in the tree
    cout << "The minimum data value in the tree: " << bst.findMinValue() << endl;

    // v. Search a value
    int searchValueToFind;
    cout << "Enter a value to search: ";
    cin >> searchValueToFind;
    if (bst.searchValue(searchValueToFind)) {
        cout << "Value " << searchValueToFind << " is found in the tree." << endl;
    } else {
        cout << "Value " << searchValueToFind << " is not found in the tree." << endl;
    }

    // iv. Swap the left and right children at every node
    bst.swapTree();
    cout << "In-order traversal after swapping left and right subtrees: ";
    inorderTraversal(bst.getRoot());
    cout << endl;

    return 0;
}
