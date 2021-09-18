#include <iostream>
#include <string>

using namespace std;

class Node{


public:
    Node *right;
    Node *left;
    int value;
};

class BinarySearchTree {
private:
    Node *root;
public:
    BinarySearchTree(Node *node) {
        root = node;
        root->right = NULL;
        root->left = NULL;
    }

    Node *add(Node *root, int node) {
        if (root == NULL) {
            root = new Node();
            root->value = node;
            root->right = root->left = NULL;

        } else if (root->value < node) {
            root->right = add(root->right, node);
        } else {
            root->left = add(root->left, node);
        }
        return root;
    }

    bool remove(Node *root, int node) {
        if (root == NULL) {
            return false;
        }
        if (root->value < node) {
            if (root->left == NULL) {
                return false;
            } else {
                root = root->left;
                bool boolean = remove(root, node);
                return true;
            }
        } else if (root->value > node) {
            if (root->right == NULL) {
                return false;
            } else {
                root = root->right;
                bool boolean = remove(root, node);
            }
        } else {
            if (root->left == NULL && root->right == NULL) {
                Node rootParent = *root;
            }
        }
    }


    Node* getParent(Node root, Node child){
        if (&child == NULL){
            return NULL;
        }if (root.right->value == child.value || root.left->value == child.value || root.value == child.value){
            return &root;
        }else {
            if (root.value < child.value){
                return getParent(*root.right, child);
            }else{
                return getParent(*root.left, child);
            }
        }
    }


    string inorder(Node *root){
        if (root == NULL){
            return "";
        }
        return inorder(root->left) +  to_string(root->value) +  " " + inorder(root->right);
    }

    string postorder(Node *root){
        if (root == NULL){
            return "";
        }
        return inorder(root->left) + inorder(root->right) +  to_string(root->value) +  " ";
    }
};

int main() {
    Node newNode;
    newNode.value = 5;
    BinarySearchTree binarySearchTree = *new BinarySearchTree(&newNode);
    binarySearchTree.add(&newNode, 2);
    binarySearchTree.add(&newNode, 1);
    binarySearchTree.add(&newNode, 4);
    binarySearchTree.add(&newNode, 3);
    binarySearchTree.add(&newNode, 10);
    binarySearchTree.add(&newNode, 9);
    //binarySearchTree.add(&newNode, 6);
    cout << binarySearchTree.inorder(&newNode) << endl;
    cout << binarySearchTree.postorder(&newNode) << endl;
    Node child;
    child.value = 10;
    cout << binarySearchTree.getParent(newNode, child)->value << endl;

    return 0;
    }
