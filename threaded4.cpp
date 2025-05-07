/*Experiment No: 4 =Consider threading a binary tree using preorder threads rather than inorder threads. 
Design an algorithm for traversal without using stack and analyze its complexity.
*/


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isLeftThreaded;
    bool isRightThreaded;

    Node(int val) {
        data = val;
        left = right = NULL;
        isLeftThreaded = false;
        isRightThreaded = false;
    }
};

class ThreadedBinaryTree {
private:
    Node* root;

    void threadTree(Node* node, Node*& prev) {
        if (node == NULL) return;
        if (node->left == NULL) {
            node->left = prev;
            node->isLeftThreaded = true;
        }
        if (prev != NULL && prev->right == NULL) {
            prev->right = node;
            prev->isRightThreaded = true;
        }
        prev = node;
        if (!node->isLeftThreaded) {
            threadTree(node->left, prev);
        }
        if (!node->isRightThreaded) {
            threadTree(node->right, prev);
        }
    }

    void reorderTraversal(Node* node) {
        while (node != NULL) {
            cout << node->data << " ";
            if (node->left && !node->isLeftThreaded) {
                node = node->left;
            } else {
                node = node->right;
                while (node && node->isLeftThreaded) {
                    cout << node->data << " ";
                    node = node->right;
                }
                if (node == NULL) {
                    break;
                }
            }
        }
    }

    // Added missing recursive preorderTraversal(Node*) method
    void preorderTraversal(Node* node) {
        if (node == NULL) return;
        cout << node->data << " ";
        if (!node->isLeftThreaded) {
            preorderTraversal(node->left);
        }
        if (!node->isRightThreaded) {
            preorderTraversal(node->right);
        }
    }

public:
    ThreadedBinaryTree() {
        root = NULL;
    }

    void insert(int data) {
        Node* newNode = new Node(data);
        if (root == NULL) {
            root = newNode;
        } else {
            Node* current = root;
            Node* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (data < current->data) {
                    current = current->left;
                } else {
                    current = current->right;
                }
            }
            if (data < parent->data) {
                parent->left = newNode;
            } else {
                parent->right = newNode;
            }
        }
    }

    void threadTree() {
        Node* prev = NULL;
        threadTree(root, prev);
    }

    void preorderTraversal() {
        cout << "Preorder Traversal (without stack) using threads: ";
        preorderTraversal(root);
        cout << endl;
    }
};

int main() {
    ThreadedBinaryTree tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);
    tree.threadTree();
    tree.preorderTraversal();
    return 0;
}
