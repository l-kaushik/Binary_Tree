#include <iostream>
#include "Tree.h"

void BinarySearchTree::Insert(int data)
{
    /*
        User only need to pass value
    */

    root = InsertRecursively(root, data);
}

Node* BinarySearchTree::InsertRecursively(Node* currentNode, int data)
{
    // Base case: if tree is empty

    if(currentNode == nullptr)
    {
        return new Node(data);
    }

    // compare then insert 

    if(data < currentNode->GetData())
    {
        currentNode->SetLeftNode(InsertRecursively(currentNode->GetLeftNode(), data));
    }
    else if(data > currentNode->GetData())
    {
        currentNode->SetRightNode(InsertRecursively(currentNode->GetRightNode(), data));
    }
    else
    {
        std::cout << "ERROR: Ordered insertion can't contain duplicate data\n";
    }

    return currentNode;

}
