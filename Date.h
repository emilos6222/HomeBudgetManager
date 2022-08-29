#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <string>
#include <ctime>

#include "AdditionalMethods.h"

using namespace std;

class Date
{
    static bool checkDate(string date);

public:

    static int getTodayDate();
    static int chooseDateYouWant();
    static int checkDaysInMonth(int month, int year);
    static int getCurrentDate();
    static int getDateFromLastMonth();
};


#endif
