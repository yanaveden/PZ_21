#include <iostream>
#include "123.h"
#include <string>
#include <fstream> 
#include "Human.h"
#include "teenager.h"

using namespace std;

int main() {

    cout << endl << "Additional task:" << endl;
    Child child("Stas", "Sinelnikov", AgeHuman::Yana, 50, 170, "-");
    child.showInfo();

    Child* child1 = new Child;
    Parent* parent1 = new Parent;
    Child* child2 = new Child;
    Parent* parent2 = new Parent;
    Teenager* teenager1 = new Teenager;

    IHuman** arr = new IHuman * [5] {child1, parent1, child2, parent2, teenager1};
    
    bool start = true;
    do
    {
        setlocale(LC_ALL, "");
        std::cout
            << "Select a person: " << std::endl
            << "1"  << std::endl << "2" << std::endl
            << "3" << std::endl << "4" << std::endl
            << "5" << std::endl << "0 = exit the program" << std::endl;
        displaySeparator();

        char choice;
        std::cin >> choice;
        switch (choice)
        {
        case '1':
            arr[0]->readFromConsole();
            break;
        case '2':
            arr[1]->readFromConsole();
            break;
        case '3':
            arr[2]->readFromConsole();
            break;
        case '4':
            arr[3]->readFromConsole();
            break;
        case '5':
            arr[4]->readFromConsole();
            break;
        case '0':
            for (int i = 0; i < 5; ++i)
            {
                arr[i]->showInfo();
                cout << "Индекс массы тела: " << arr[i]->calculateBMI() << endl;
                cout << "Год рождения: " << arr[i]->calculateBirthYear(2024);

                displaySeparator();
            }
            start = false;
            break;
        default:
            break;
        }
    } while (start);

    std::ofstream out("Human.txt", std::ios::out | std::ios::trunc);
    out.close();

    for (int i = 0; i < 5; ++i)
    {
        arr[i]->writeToFile();
        std::cout << "Person \"" << arr[i]->getSurname() << "\" successfully written to file." << std::endl;
    }

    delete child1;
    delete parent1;
    delete child2;
    delete parent2;
    delete teenager1;
    delete[] arr;

    return 0;
}
