#pragma once
#include "123.h"
#include "Human.h"

class Teenager : public Child, Parent {
public:
    ~Teenager();
    Teenager();
    
    Teenager(std::string fName, std::string sName, int age,
             int weight, int height, std::string toy,
             bool isDocument, std::string education);
    
    void setEducation(std::string education);
    std::string getEducation();

    Teenager operator++();
    Teenager operator--();

    bool operator< (Teenager other);
    bool operator> (Teenager other);

    friend std::ostream& operator<< (std::ostream& output, Teenager t);

    void readFromConsole();
    void showInfo();
    void writeToFile();

private:
    std::string _education; 
};
