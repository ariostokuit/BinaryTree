#include <iostream>
#include <string>
using namespace std;

class Employee{
private:
    string name;
    int ID_num;

public:
    Employee(): name(""), ID_num(0) {};
    Employee(string n, int id):name(n), ID_num(id){};
    string getName(){return name;}
    int getID_num() {return ID_num;}
};

struct Employee_TreeNode{
    Employee data_;
    Employee_TreeNode *left, *right;
    Employee_TreeNode(Employee d, Employee_TreeNode *left1 = nullptr, Employee_TreeNode *right1 = nullptr){
        data_ = d;
        left = left1;
        right = right1;
    }
};

class BT_Employee{
private:
    Employee_TreeNode *root;
    size_t size;
    void insert(Employee_TreeNode *&, Employee);
    void displayInOrder(Employee_TreeNode *);
    
public:
    BT_Employee();
    void insert(Employee);
    void display(); 
    void searchEmployee(int);
  
};