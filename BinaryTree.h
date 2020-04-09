//
//  BinaryTree.hpp
//  BinaryTree
//
//  Created by Ariosto Kuit on 11/6/19.
//  Copyright © 2019 Ariosto Kuit. All rights reserved.
//

#include <iostream>
using namespace std;

struct TreeNode
{
    int data_;
    TreeNode * left, *right;
    
    TreeNode(int d, TreeNode * left1 = nullptr,TreeNode *right1 = nullptr){
        data_ = d;
        left = left1;
        right = right1;
    }
};

class BinaryTree
{
public:
    BinaryTree();
    BinaryTree(int);
    void insert(int);
    void deleteSubTree();
    void displayInOrder() const;
    void displayPreOrder() const;
    void displayPostOrder() const;
    bool isEmpty();
    bool search(int) const;
    size_t getSize();
    
private:
    TreeNode* root; //Pointer to the root of the tree
    size_t size_;

    void insert(TreeNode *&, int);
    void showInOrder(TreeNode *) const;
    void showPreOrder(TreeNode *) const;
    void showPostOrder(TreeNode *)const;
};
