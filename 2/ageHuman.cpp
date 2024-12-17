#include <iostream>
#include <string>
#include "age.h"
using namespace std;

string age::correctAlpha(string str) {
    for (int i = 0; i < str.length(); i++) {
        if (!isalpha(str.at(i)) && !ispunct(str.at(i))) {
            cout << "Некорректный ввод данных!" << endl << "----------" << endl;
            return "undefined";
        }
    }
    if (!(str == "undefined")) return str;
    else return str;
}


int age::correctCount(int count)
{
    if (count >= 0)
        return count;
    else
    {
        cout << "Некорректный ввод данных!" << endl
             << "----------" << endl;
        return 0;
    }
}

void age::displaySeparator()
{
    std::cout << "___________________________________________" << std::endl;
}
