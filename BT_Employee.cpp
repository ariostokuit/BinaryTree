#include <iostream>
#include <iomanip>
#include "BT_Employee.h"
using namespace std;

BT_Employee::BT_Employee(){
    root = nullptr;
}

void BT_Employee::insert(Employee_TreeNode *& tree,Employee value){
   if(tree == nullptr){
       tree = new Employee_TreeNode(value);
       return;
   }
   if(tree->data_.getID_num() == value.getID_num()){
       cout << "Error: employee already exist\n";
       return;
   }
   if(value.getID_num() < tree->data_.getID_num()){
       insert(tree->left,value);
   }
   else{
       insert(tree->right,value);
   }
}

void BT_Employee::insert(Employee value){
    insert(root,value);
}


void BT_Employee::displayInOrder(Employee_TreeNode * tree){
    if(tree != nullptr){
    cout << tree->data_.getID_num() << setw(20) << tree->data_.getName() << endl;
    displayInOrder(tree->left);
    displayInOrder(tree->right);
    }
}

void BT_Employee::display(){
    cout << "Employee ID " << setw(15) << "Name" << endl;
    displayInOrder(root);
}

void BT_Employee::searchEmployee(int key) {
    Employee_TreeNode *Position = root;

    while(Position != nullptr)
    {
        if(key == Position->data_.getID_num())
        {
            cout << "Employee found!\n";
            cout << "ID: " << key << endl;
            cout << "Name: " << Position->data_.getName() << endl;
            return;
        }
        else if(key > Position->data_.getID_num())
        {
            Position = Position->right;
        }
        else
            Position = Position->left;
    }
    cout << "Error: Employee ID does not exist\n";   
}