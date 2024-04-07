#include <iostream>
#include "Tree.h"

int main()
{
    BinarySearchTree a;

    a.Insert(7);
    a.Insert(5);
    a.Insert(12);
    a.Insert(3);
    a.Insert(6);
    a.Insert(9);
    a.Insert(15);
   
    Node* temp = a.Search(9);
    std::cout << temp->GetData();
}