#include <iostream>
#include <queue>
#include "Tree.h"

// Insertion

void BinarySearchTree::Insert(int data)
{
    /*
        User only need to pass value
    */

    root = InsertRecursively(root, data);
}

Node *BinarySearchTree::InsertRecursively(Node *currentNode, int data)
{
    // Base case: if tree is empty

    if (currentNode == nullptr)
    {
        return new Node(data);
    }

    // compare then insert

    if (data < currentNode->GetData())
    {
        currentNode->SetLeftNode(InsertRecursively(currentNode->GetLeftNode(), data));
    }
    else if (data > currentNode->GetData())
    {
        currentNode->SetRightNode(InsertRecursively(currentNode->GetRightNode(), data));
    }
    else
    {
        std::cout << "ERROR: Ordered insertion can't contain duplicate data\n";
    }

    return currentNode;
}

// Searching

Node* BinarySearchTree::Search(int data)
{
    return SearchRecursive(root, data);
}

Node* BinarySearchTree::SearchRecursive(Node* currentNode, int data)
{
    // Base case
    if(currentNode == nullptr)
    {
        return nullptr;
    }

    if(data == currentNode->GetData())
    {
        return currentNode;
    }

    if(data < currentNode->GetData())
    {
       return SearchRecursive(currentNode->GetLeftNode(), data);
    }

    if(data > currentNode->GetData())
    {
       return SearchRecursive(currentNode->GetRightNode(), data);
    }

    return nullptr;
}

// Traversal

// also known as Breadth First Search
void BinarySearchTree::LevelOrderTraversal()
{
    std::queue<Node *> q;
    q.push(root);
    q.push(NULL); // level separator

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        if (temp == NULL) // previous level traversal is finished
        {
            std::cout << "\n";

            if (!q.empty()) // queue still has some child nodes
            {
                q.push(NULL);
            }
        }
        else
        {
            std::cout << temp->GetData() << " ";

            if (temp->GetLeftNode())
            {
                q.push(temp->GetLeftNode());
            }

            if (temp->GetRightNode())
            {
                q.push(temp->GetRightNode());
            }
        }
    }
}

void BinarySearchTree::BreadthFirstSearch()
{
    LevelOrderTraversal();
}

void BinarySearchTree::InOrderTraversal()
{
    // prints elements in ascending order

    InOrderRecursive(root);
}

void BinarySearchTree::PreOrderTraversal()
{
    PreOrderRecursive(root);
}

void BinarySearchTree::PostOrderTraversal()
{
    PostOrderRecursive(root);
}

void BinarySearchTree::InOrderRecursive(Node* currentNode)
{
    /*
        Works on LNR rule
        L for left node
        N for print data of current node
        R for right node    
    */

    // base case
    if(currentNode == nullptr){
        return;
    }

    InOrderRecursive(currentNode->GetLeftNode());          // L
    std::cout << currentNode->GetData() << ' ';            // N
    InOrderRecursive(currentNode->GetRightNode());         // R
}

void BinarySearchTree::PreOrderRecursive(Node* currentNode)
{
    /*
        Works on NLR rule
        N for print data of current node
        L for left node
        R for right node    
    */

    // base case
    if(currentNode == nullptr){
        return;
    }

    std::cout << currentNode->GetData() << ' ';            // N
    PreOrderRecursive(currentNode->GetLeftNode());          // L
    PreOrderRecursive(currentNode->GetRightNode());         // R
}

void BinarySearchTree::PostOrderRecursive(Node* currentNode)
{
    /*
        Works on LRN rule
        L for left node
        R for right node    
        N for print data of current node
    */

    // base case
    if(currentNode == nullptr){
        return;
    }

    PostOrderRecursive(currentNode->GetLeftNode());          // L
    PostOrderRecursive(currentNode->GetRightNode());         // R
    std::cout << currentNode->GetData() << ' ';            // N
}