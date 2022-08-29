#ifndef ADDITIONALMETHODS_H
#define ADDITIONALMETHODS_H

#include <iostream>
#include <string>

using namespace std;

class AdditionalMethods
{
public:

    static char getOneChar();
    static string toUpperFirstLetter(string wordToUpper);
    static string addDashesInDate(int date);
    static int removeDashesFromStringDateToInt(string date);
    static int dateStringToInt(string date);

};

#endif
