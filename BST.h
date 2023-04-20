#pragma once
#include<iostream>
using namespace std;

template <typename T>
class Node {

public:
    T data;
    int level;
    Node<T>* left; Node<T>* right;
    Node(T data) {
        this->data = data;
        level = 0;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BST {
private:
    Node<T>* root;
    bool mirror;
    bool found;

public:
    BST() {
        root = NULL;
        mirror = false;
        found = false;
    }
    //~BST(); //delete all children
    Node<T>* returnRoot() { return root; }
    void setMirror() { 
        if (mirror) {
            mirror = false;
        }
        else {
            mirror = true;
        }
       }
    bool returnFound() { return found; }

    void Insert(T data) {
        if (mirror == true) {
            InsertMirror(data);
            return;
        }
        Node<T>* temp = new Node<T>(data);
        if (root == NULL) {
            root = temp;
        }
        else if (temp->data < root->data) {
            temp->level++;
            InsertTraversal(temp, root->left);
        }
        else {
            temp->level++;
            InsertTraversal(temp, root->right);
        }
    }
    void InsertTraversal(Node<T>* temp, Node<T>*& root) {
        if (root == NULL) {
            root = temp;
        }
        else if (temp->data < root->data) {
            temp->level++;
            InsertTraversal(temp, root->left);
        }
        else {
            temp->level++;
            InsertTraversal(temp, root->right);
        }
    }

    void InsertMirror(T data) {
        Node<T>* temp = new Node<T>(data);
        if (root == NULL) {
            root = temp;
        }
        else if (temp->data > root->data) {
            temp->level++;
            InsertTraversalMirror(temp, root->left);
        }
        else {
            temp->level++;
            InsertTraversalMirror(temp, root->right);
        }
    }
    void InsertTraversalMirror(Node<T>* temp, Node<T>*& root) {
        if (root == NULL) {
            root = temp;
        }
        else if (temp->data > root->data) {
            temp->level++;
            InsertTraversalMirror(temp, root->left);
        }
        else {
            temp->level++;
            InsertTraversalMirror(temp, root->right);
        }
    }

    void PrintLevel(ostream& out, int level) {
        found = false;
        if (root->level == level) {
            found = true;
            out << root->data << " ";
            return;
        }
        else {
            PrintLevelTraversal(out,root->left, level);
            PrintLevelTraversal(out,root->right, level);
        }
    }
    void PrintLevelTraversal(ostream& out,Node<T>* root, int level) {
        if (root == NULL) {
            return;
        }
        else if (root->level == level) {
            found = true;
            out << root->data << " ";
            return;
        }
        else {
            PrintLevelTraversal(out,root->left,level);
            PrintLevelTraversal(out,root->right,level);
        }

    }

    void leftRight(ostream& out) {
        if (root == NULL) {
            return;
        }
        PrintInOrder(out,root->left);
        out << root->data << " ";
        PrintInOrder(out,root->right);
    }
    void PrintInOrder(ostream& out,Node<T>* root) {
        if (root == NULL) {
            return;
        }
        PrintInOrder(out, root->left);
        out << root->data << " ";
        PrintInOrder(out,root->right);
    }

    void Mirror() {
        if ( (root == NULL) || (root->left == NULL && root->right == NULL) ){
            return;
        }
        else {
            cout << "root: " << root->data << " " << endl;
            Swap(root->left, root->right);
            MirrorSwap(root->left);
            MirrorSwap(root->right);
        }
    }
    void MirrorSwap(Node<T>*& root) {
        if ((root == NULL) || (root->left == NULL && root->right == NULL)) {
            return;
        }
        else {
            Swap(root->left, root->right);
            MirrorSwap(root->left);
            MirrorSwap(root->right);
        }
    }
    void Swap(Node<T>*& left, Node<T>*& right) {
        Node<T>* temp = left;
        left = right;
        right = temp;
    }
};