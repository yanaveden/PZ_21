#include "123.h"
#include <cmath>
#include "age.h"

IHuman::~IHuman() {}

IHuman::IHuman() : IHuman("undefined", "undefined", 0, 0, 0) {}

IHuman::IHuman(std::string fName, std::string sName, int age, int weight, int height) :
_firstName(correctAlpha(fName)), _surname(correctAlpha(sName)), _age(correctCount(age)),
_weight(correctCount(weight)), _height(correctCount(height)) {}

double IHuman::calculateBMI()
{
    return (_weight / 2.205) / pow((_height / 39.37), 2);
}

int IHuman::calculateBirthYear(int currentYear)
{
    return currentYear - _age;
}
string IHuman::getFirstName() { return _firstName; }
string IHuman::getSurname() { return _surname; }
int IHuman::getAge() { return _age; }
int IHuman::getWeight() { return _weight; }
int IHuman::getHeight() { return _height; }


void IHuman::setFirstName(string firstName)
{
    this->_firstName = correctAlpha(firstName);
}

void IHuman::setSurname(string surname)
{
    this->_surname = correctAlpha(surname);
}

void IHuman::setAge(int age)
{
    this->_age = correctCount(age);
}

void IHuman::setWeight(int weight)
{
    if (weight >= 0)
    {
        this->_weight = correctCount(weight);
    }
    else
    {
        cout << "Error: incorrect weight!" << endl;
    }
}

void IHuman::setHeight(int height)
{
    if (height >= 0)
    {
        this->_height = correctCount(height);
    }
    else
    {
        cout << "Error: incorrect height!" << endl;
    }
}

void IHuman::showInfo()
{
    std::cout << "Name: " << _firstName << "\n";
    std::cout << "Surname: " << _surname << "\n";
    std::cout << "Age: " << _age << "\n";
    std::cout << "Weight: " << _weight << " kg\n";
    std::cout << "Height: " << _height << " sm\n";
}

void IHuman::writeToFile() {}

void IHuman::readFromConsole()
{
    setlocale(LC_ALL, ""); 
    std::cout << "Enter first name: "; std::cin >> _firstName;
    std::cout << "Enter surname: "; std::cin >> _surname;
    std::cout << "Enter age: "; std::cin >> _age;
    std::cout << "Enter weight in kg: "; std::cin >> _weight;
    std::cout << "Enter height in cm: "; std::cin >> _height;
}
