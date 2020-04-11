#include <iostream>
#include "BinaryTree.cpp"
#include "BT_Employee.cpp"
#include <fstream>
#include <queue>
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


    //testing BT_Employeee

    //read Employee.txt
    fstream file;
    string fname, lname, name;
    int idNum;
    queue <Employee> EmployeeQueue;

    file.open("Employee.txt");

    if(!file.is_open()){
        cout << "Unable to open file\n";
        return 0;
    }

    while(file >> idNum >> fname >> lname){
        name = fname + " " + lname;
        EmployeeQueue.push(Employee(name, idNum));
    }

    file.close();

    // while(!EmployeeQueue.empty()){
    //     Employee e = EmployeeQueue.front();
    //     cout << e.getID_num() << " " << e.getName() << endl;
    //     EmployeeQueue.pop();
    // } 

    BT_Employee EmployeeTree;

    while(!EmployeeQueue.empty()){
        EmployeeTree.insert(EmployeeQueue.front());
        EmployeeQueue.pop();
    }
    
    EmployeeTree.display();


    cout << "Enter the Employee ID number that you want to search: ";
    cin >> idNum;

    EmployeeTree.searchEmployee(idNum);

    return 0;
}