#pragma once

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
    int GetData(Node * node){return node->data;}
    Node* GetLeftNode(Node* node){return node->left;}
    Node* GetRightNode(Node* node){return node->right;}
    
    //setter
    void SetData(Node * node, int data){node->data = data;}
    void SetLeftNode(Node* node, Node* LeftNode){node->left = LeftNode;}
    void SetRightNode(Node* node, Node* RightNode){node->right = RightNode;}

};
