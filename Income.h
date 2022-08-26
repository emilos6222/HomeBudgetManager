#ifndef INCOME_H
#define INCOME_H

#include <iostream>
#include <string>

using namespace std;

class Income
{
    int incomeId;
    int userId;
    int date;
    string item;
    double amount;

public:
    int getIncomeId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setIncomeId(int incomeId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
};

#endif
