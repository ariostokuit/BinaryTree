#include <iostream>
#include "BinaryTree.cpp"
using namespace std;

int main()
{
    BinaryTree numTree; 

    numTree.insert(50);
    numTree.insert(25);
    numTree.insert(75);
    numTree.insert(100);
    numTree.insert(40);
    numTree.insert(80);
    numTree.insert(90);

    numTree.displayInOrder();
    numTree.displayPreOrder();
    numTree.displayPostOrder();
    return 0;
}