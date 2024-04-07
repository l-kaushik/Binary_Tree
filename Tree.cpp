#include <iostream>
#include <queue>
#include "Tree.h"

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
