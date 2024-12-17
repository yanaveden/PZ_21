#include "Human.h"
#include <cmath>
#include "age.h"
#include "123.h"
#include <fstream>

Child::~Child() {}

Child::Child()
{
    setFirstName("undefined");
    setSurname("undefined");
    setAge(0);
    setWeight(0);
    setHeight(0);
    this->_toy = "undefined";
}

Child::Child(std::string fName, std::string sName, int age, int weight, int height, std::string toy) : 
IHuman(fName, sName, age, weight, height), _toy(correctAlpha(toy)) {}
Child::Child(std::string toy) : _toy(correctAlpha(toy)) {}


string Child::getToy()
{
    return _toy;
}

void Child::setToy(string toy)
{
    this->_toy = correctAlpha(toy);
}

void Child::showInfo()
{
    IHuman::showInfo();
    std::cout << "Toy: " << _toy << std::endl;
}

void Child::readFromConsole() {
    IHuman::readFromConsole(); 
    std::cout << "Enter the toy: "; 
    std::cin >> _toy; 
}

void Child::writeToFile()
{
    std::ofstream out;
    out.open("Human.txt", std::ios::app);
    
    if (out.is_open())
    {
        out << "First Name: " << getFirstName() << std::endl
            << "Surname: " << getSurname() << std::endl
            << "Age: " << getAge() << std::endl
            << "Weight in kg: " << getWeight() << std::endl
            << "Height in cm: " << getHeight() << std::endl
            << "Toy: " << _toy << std::endl 
            << "_____________________________________________" << std::endl;
    }
    
    out.close();
}
// ---------------------------------------

Parent::Parent()
{
    setFirstName("undefined");
    setSurname("undefined");
    setAge(0);
    setWeight(0);
    setHeight(0);
    this->_isDocument = false;
}

Parent::Parent(std::string fName, std::string sName, int age, int weight, int height, bool isDocument) : 
IHuman(fName, sName, age, weight, height), _isDocument(isDocument) {}
Parent::Parent(std::string isDocument) : _isDocument(isDocument == "true") {}

bool Parent ::getDocument()
{
    return _isDocument;
}

void Parent ::setDocument(bool isDocument)
{
    this->_isDocument = isDocument;
}

void Parent::showInfo() {
    IHuman::showInfo();
    std::cout << "Has Document: " << (_isDocument ? "Yes" : "No") << std::endl; 
}

void Parent::readFromConsole()
{
    IHuman::readFromConsole(); 
    std::cout << "Enter if the human has a document (1 for Yes / 0 for No): "; 
    std::cin >> _isDocument; 
}

void Parent::writeToFile()
{
    std::ofstream out;
    out.open("Human.txt", std::ios::app);
    
    if (out.is_open())
    {
        out << "First Name: " << getFirstName() << std::endl
            << "Surname: " << getSurname() << std::endl
            << "Age: " << getAge() << std::endl
            << "Weight in kg: " << getWeight() << std::endl
            << "Height in cm: " << getHeight() << std::endl
            << "Has Document: " << (getDocument() ? "Yes" : "No") << std::endl 
            << "_____________________________________________" << std::endl;
    }
    
    out.close();
}
