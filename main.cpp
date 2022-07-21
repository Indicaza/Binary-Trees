//
// Created by Zach Reitmeier on 7/21/22.
//
#include <iostream>
#include <vector>
#include <string>


// create a class called BinaryTree
// this class will be used to create a binary tree
// each node in the tree will store a string


class BinaryTree {
public:
    struct Node {
        std::string word;
        Node* left;
        Node* right;
    };

    root = nullptr;
    std::vector<std::string> words;


    // create a constructor for the BinaryTree class
    // this constructor will create a root node
    // the root node will have a nullptr for left and right children
    BinaryTree() {
        root->word = "";
        root->left = nullptr;
        root->right = nullptr;
    }


    // create a method that destroys the tree
    // this method will destroy the tree by deleting all nodes
    // this method will be called in the destructor of the BinaryTree class
    void destroyTree(Node* node) {
        if (node == nullptr) {
            return;
        }
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }

    // create the destructor for the BinaryTree class
    // this destructor will call the destroyTree method
    ~BinaryTree() {
        destroyTree(root);
    }


    void addNode(std::string word) {
        Node* newNode = new Node;
        newNode->word = word;
        newNode->left = nullptr;
        newNode->right = nullptr;
        if (root == nullptr) {
            root = newNode;
        } else {
            Node* current = root;
            while (true) {
                if (word < current->word) {
                    if (current->left == nullptr) {
                        current->left = newNode;
                        break;
                    } else {
                        current = current->left;
                    }
                } else {
                    if (current->right == nullptr) {
                        current->right = newNode;
                        break;
                    } else {
                        current = current->right;
                    }
                }
            }
        }
    }


    // create a method that takes a vector of strings as a parameter and adds them to the tree
    // this method will iterate through the vector and add each string to the tree
    void addNodes(std::vector<std::string> words) {
        for (int i = 0; i < words.size(); i++) {
            addNode(words[i]);
        }
    }






};




int main() {


    return 0;
}