#pragma once

#define NULLVALUE -1;

class Node
{
private:
    int data{int()};
    Node* left {nullptr};
    Node* right {nullptr};

public:

    //constructor
    Node() = default;
    Node(int inData = int(), Node* inLeft = nullptr, Node* inRight = nullptr) : data(inData), left(inLeft), right(inRight) {}

    //getter
    int GetData(){return this->data;}
    Node* GetLeftNode(){return this->left;}
    Node* GetRightNode(){return this->right;}
    
    //setter
    void SetData(int inData){this->data = inData;}
    void SetLeftNode(Node* LeftNode){this->left = LeftNode;}
    void SetRightNode(Node* RightNode){this->right = RightNode;}

};

class BinarySearchTree
{
    Node * root{nullptr};
private:
    // insertion
    Node* InsertRecursively(Node* currentNode, int data);

    // searching
    Node* SearchRecursive(Node* currentNode, int data, Node*& outPrev);

    //Traversal
    void InOrderRecursive(Node * currentNode);
    void PreOrderRecursive(Node * currentNode);
    void PostOrderRecursive(Node * currentNode);

public:
    // insertion
    void Insert(int data);

    // searching
    Node* Search(int data);

    // deletion
    bool remove(int data);

    //Traversal
    void LevelOrderTraversal();
    void BreadthFirstSearch();

    void InOrderTraversal();
    void PreOrderTraversal();
    void PostOrderTraversal();
};