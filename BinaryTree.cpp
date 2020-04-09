//
//  BinaryTree.cpp
//  BinaryTree
//
//  Created by Ariosto Kuit on 11/6/19.
//  Copyright © 2019 Ariosto Kuit. All rights reserved.
//
#include "BinaryTree.h"
using namespace std;

BinaryTree::BinaryTree(){
   root = nullptr;
   size_ = 0;
}

BinaryTree::BinaryTree(int val)
{
   insert(root,val);
   size_++;
}


/*
* void insert(TreeNode *&,int) is private function 
* that will add a new node into the tree in order
*/
void BinaryTree::insert(TreeNode *&tree, int val)
{
    //if the tree is empty 
    if(tree == nullptr) 
    {
        tree = new TreeNode(val);
        return;
    }

    //If the value inputed is equal or exists then no need to add
    if(tree->data_ == val){
        cout << "Error, number already exists in the Tree\n";
        return;
    }

    //if value is left then the current node data then move to left
    if(val < tree->data_) 
    {
        insert(tree->left,val);
    }
    else //move to right if greater than current Node value
        insert(tree->right,val);
}

void BinaryTree::insert(int val)
{
    insert(root, val);
}


/*
* bool isEmpty() will check if the tree is empty
*
*/
bool BinaryTree::isEmpty()
{
    if(root == nullptr){return true;}
    return false;
}

size_t BinaryTree::getSize(){ return size_;}

/*************************************************
 * showInOrder(TreeNode *tree) will help display the
 * tree in order by implementing recursively
 * ***********************************************/
void BinaryTree::showInOrder(TreeNode *tree)const
{
    if(tree) //if the tree is not a nullptr
    {
        showInOrder(tree->left); //then go to the left until null
        cout << tree->data_ << " "; //print the value 
        showInOrder(tree->right); //then go the right 
    }
}

void BinaryTree::displayInOrder()const{
    cout << "Inorder traversal \n";
    showInOrder(root);
    cout << endl;
}

void BinaryTree::showPreOrder(TreeNode *tree) const
{
    if(tree != nullptr)
    {
        cout << tree->data_ << " ";
        showPreOrder(tree->left);
        showPreOrder(tree->right);
    }
}

void BinaryTree::displayPreOrder() const{
    cout << "PreOrder Traversal\n";
    showPreOrder(root);
    cout << endl;
}

void BinaryTree::showPostOrder(TreeNode *tree)const{
    if(tree != nullptr)
    {
        showPostOrder(tree->left);
        showPostOrder(tree->right);
        cout << tree->data_ << " ";
    }
}

void BinaryTree::displayPostOrder()const{
cout << "PostOrder Traversal\n";
showPostOrder(root);
cout << endl;
}

bool BinaryTree::search(int key) const{
    TreeNode *Position = root;

    while(Position != nullptr)
    {
        if(key == Position->data_)
        {
            return true;
        }
        else if(key > Position->data_)
        {
            Position = Position->right;
        }
        else
            Position = Position->left;
    }
    return false;
}

