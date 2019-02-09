//  Build and process data in a heap
//
//  Requirement:
//  Build heap from file
//  Print heap as an indented tree
//  Print customers in priority sequence
//  Heap class
//  Template
//  main(), and other functions

#include "Passengers.h"
#include "MaxHeap.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

//Function Prototypes
void printInfo();
void printEnd();
void readData(string fileName, MaxHeap<Passenger> &heap);
void printTreeManager(MaxHeap<Passenger> &heap);
void printPriorityrManager(MaxHeap<Passenger> &heap);

int main(void)
{
    string fileName = "overbooked.txt";
    MaxHeap<Passenger> heap;
    printInfo();
    readData(fileName, heap);
    printTreeManager(heap);
    printPriorityrManager(heap);
    printEnd();
    return 0;
}

//Print heap as indented tree
void printTreeManager(MaxHeap<Passenger> &heap)
{
    int counter = 0;
    cout << "=========== Print the heap as indented tree ===========" << endl << endl;
    heap.printIndented(counter, counter);
    return;
}

//Print customers in priority sequence
void printPriorityrManager(MaxHeap<Passenger> &heap)
{
    cout << "\n========= Print customers in priority sequence =========" << endl << endl;
    Passenger temp;
    int numofItems = heap.getNumElements();
    for(int i =0; i < numofItems; i++){
        temp = heap.remove();
        cout << i + 1 << ". " << temp.getSerialNum()<< " " << temp.getcusName() << endl;
    }
    return;
}

//read data from file and insert to heap
void readData(string fileName, MaxHeap<Passenger> &heap)
{
    int count = 0;
    int intTemp = 0;
    string temp = "";
    bool insert;
    
    ifstream inputfile;
    inputfile.open(fileName);
    if(!inputfile.good())
    {
        cout <<"Error opening file!\n";
        exit(-1);
    }

    while (!inputfile.eof())
    {
        Passenger *pass = new Passenger;
        
        inputfile >> intTemp;
        pass->setYear(intTemp);
        
        inputfile >> intTemp;
        pass->setTotalMileage(intTemp);
        
        inputfile.ignore();
        getline(inputfile, temp, '\r');
        pass->setcusName(temp);
        
        count++;
        pass->setSequenceNum(count);
        pass->calculatePriority();
        pass->calculateSerialNum();
        
        insert = heap.insert(*pass);
    }
    
    return;
}
//**************************************************
// Print info about the project
//**************************************************
void printInfo()
{
    cout << "CIS 22C-02Y\n";
    cout << "M/W 1:30 - 3:20\n";
    cout << "Professor Delia Gârbacea\n";
    cout << "Trinh Nguyen\n";
    cout << "March 15, 2017\n";
    cout << "Homework #5\n\n";
    cout << "\t\t Build and Process a Heap Data Structure\n\n";
}
//***************************************************************
// The printEnd function prints out farewell message to         *
// passenger.                                                   *
//***************************************************************

void printEnd()
{
    cout << "\nEnd of program. Good Bye!\n\n";
}

