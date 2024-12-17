#include "123.h"
using namespace std;
using namespace age;
#pragma once
#include <string>
#include <iostream>


class Child : virtual public IHuman {
public:
    ~Child();

    Child(std::string fName, std::string sName, int age, int weight, int height, std::string toy);
    Child();
    Child(std::string toy);

    std::string getToy();
    void setToy(std::string toy);
    
    void showInfo();
    void readFromConsole();
    void writeToFile();

private:
    std::string _toy;
};

class Parent : virtual public IHuman {
public:
    ~Parent() {}

    Parent(std::string fName, std::string sName, int age, int weight, int height, bool isDocument);
    Parent();
    Parent(std::string isDocument);

    bool getDocument();
    void setDocument(bool isDocument);
    
    void showInfo();
    void readFromConsole();
    void writeToFile();

private:
    bool _isDocument;
};
