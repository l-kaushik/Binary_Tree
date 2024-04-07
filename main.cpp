#include <iostream>
#include "Tree.h"

int main()
{
    BinarySearchTree a;

    a.Insert(5);
    a.Insert(6);
    a.Insert(3);
    a.Insert(1);
    a.Insert(4);
    a.Insert(8);

    a.LevelOrderTraversal();
}