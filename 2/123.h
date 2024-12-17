#pragma once
#include <iostream>
#include <string>
#include "age.h"
using namespace age;
using namespace std;


class IHuman {
public:
    virtual ~IHuman();

    IHuman(std::string fName, std::string sName, int age, int weight, int height);
    IHuman();

    string getFirstName();
    string getSurname();
    int getAge();
    int getWeight();
    int getHeight();

    void setFirstName(string firstName);
    void setSurname(string surname);
    void setAge(int age); 
    void setWeight(int weight);
    void setHeight(int height);

    virtual void showInfo();
    virtual void readFromConsole() = 0; 
    virtual void writeToFile();
    
    double calculateBMI(); 
    int calculateBirthYear(int currentYear); 
    
private:
    string _firstName; 
    string _surname;   
    int _age; 
    int _weight;
    int _height;
};
