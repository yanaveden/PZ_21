#include "teenager.h"
#include <fstream>

Teenager::Teenager() : Teenager("undefined", "undefined", 0, 0, 0, "undefined", false, "undefined") {}

Teenager::Teenager(std::string fName, std::string sName, int age,
                   int weight, int height, std::string toy, bool isDocument, std::string education)
    : Child(fName, sName, age, weight, height, toy),
      Parent(fName, sName, age, weight, height, isDocument),
      _education(correctAlpha(education)) {}

Teenager::~Teenager() {}

void Teenager::setEducation(std::string education)
{
    this->_education = correctAlpha(education);
}

std::string Teenager::getEducation()
{
    return _education;
}

Teenager Teenager::operator++()
{
    setHeight(getHeight() + 10);
    return *this;
}

Teenager Teenager::operator--()
{
    if (getHeight() > 10)
    {
        setHeight(getHeight() - 10);
    }
    else
    {
        std::cout << "Height is less than 0!" << std::endl;
    }
    return *this;
}

bool Teenager::operator<(Teenager other)
{
    return this->getHeight() < other.getHeight();
}

bool Teenager::operator>(Teenager other)
{
    return this->getHeight() > other.getHeight();
}

void Teenager::readFromConsole()
{
    IHuman::readFromConsole();
    std::cout << "Enter the toy: ";
    std::string toy;
    std::cin >> toy;
    setToy(toy);

    std::cout << "Enter if the teenager has a document (1 for Yes / 0 for No): ";
    bool hasDocument;
    std::cin >> hasDocument;
    setDocument(hasDocument);

    std::cout << "Enter education: ";
    std::string education;
    std::cin >> _education;
}

void Teenager::showInfo()
{
    IHuman::showInfo();
    std::cout << "Toy: " << getToy() << std::endl;
    std::cout << "Has Document: " << getDocument() << std::endl;
    std::cout << "Education: " << _education << std::endl;
}

std::ostream &operator<<(std::ostream &output, Teenager t)
{
    output << "First Name: " << t.getFirstName() << "\n"
           << "Surname: " << t.getSurname() << "\n"
           << "Age: " << t.getAge() << "\n"
           << "Weight: " << t.getWeight() << " kg\n"
           << "Height: " << t.getHeight() << " cm\n"
           << "Toy: " << t.getToy() << "\n"
           << "Has Document: " << (t.getDocument() ? "Yes" : "No") << "\n"
           << "Education: " << t._education << "\n"
           << "__________________________________" << "\n";
    return output;
}

void Teenager::writeToFile()
{
    std::ofstream out;
    out.open("Human.txt", std::ios::app);

    if (out.is_open())
    {
        out << "First Name: " << getFirstName() << std::endl
            << "Surname: " << getSurname() << std::endl
            << "Age: " << getAge() << std::endl
            << "Weight: " << getWeight() << std::endl
            << "Height: " << getHeight() << std::endl
            << "Toy: " << getToy() << std::endl
            << "Has Document: " << (getDocument() ? "Yes" : "No") << std::endl
            << "Education: " << _education << std::endl
            << "__________________________________" << std::endl;
    }

    out.close();
}
