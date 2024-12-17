#pragma once
#include <string>
using namespace std;

namespace age
{
    enum AgeHuman
    {
        Yana = 18,
        Stas = 25,
        Yana2 = 35,
        Stas1 = 52
    };

    string correctAlpha(string str);
    int correctCount(int count);
    void displaySeparator();
}
