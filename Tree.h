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
    void SetData(int data){this->data = data;}
    void SetLeftNode(Node* LeftNode){this->left = LeftNode;}
    void SetRightNode(Node* RightNode){this->right = RightNode;}

};

class BinarySearchTree
{
    Node * root{nullptr};
protected:
    Node* InsertRecursively(Node* currentNode, int data);

public:
    void Insert(int data);
};