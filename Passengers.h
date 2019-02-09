//
//  Passengers.h
//  22C_HW5
//

#ifndef Passengers_h
#define Passengers_h

#include <string>
#include <iostream>
using namespace std;

class Passenger;

class Passenger{
private:
    int year;
    int totalMileage;
    string cusName;
    
    int priority;
    int serialNum;
    int sequenceNum;
    
public:
    
    //Constructor
    Passenger() { year = 0; totalMileage = 0; cusName = ""; priority = 0; serialNum = 0;}
    
    //Setter Functions
    void setYear(int year){this->year = year;}
    void setTotalMileage(int totalMileage){this->totalMileage = totalMileage;}
    void setcusName(string cusName){this->cusName = cusName;}
    void setPriority(int priority) {this->priority = priority;}
    void setSerialNum(int serialNum) {this->serialNum = serialNum;}
    void setSequenceNum(int sequenceNum) {this->sequenceNum = sequenceNum;}
    
    //Getter Functions
    int getYear() {return year;}
    int getTotalMileage() {return totalMileage;}
    string getcusName() {return cusName;}
    int getPriority() {return priority;}
    int getSerialNum() {return serialNum;}
    int getSequenceNum() {return sequenceNum;}
    
    //Calculate priority number and serial number
    void calculatePriority() {setPriority(totalMileage/1000 + year - sequenceNum);}
    void calculateSerialNum() {setSerialNum(priority * 100 + (100 - sequenceNum));}
    
    // Overloaded operator functions
    
    bool operator<(Passenger &right) { return (serialNum < right.serialNum);}
    
    bool operator<=(Passenger &right) { return (serialNum <= right.serialNum);}
    
    bool operator==(Passenger &right) { return (serialNum == right.serialNum);}
    
    bool operator>(Passenger &right) {return (serialNum > right.serialNum);}
    
    //Friend function
    friend ostream &operator<<(ostream &strm, const Passenger &obj)
    {
        strm << obj.serialNum << " " << obj.cusName;
        return strm;
    }
};

#endif /* Passengers_h */
