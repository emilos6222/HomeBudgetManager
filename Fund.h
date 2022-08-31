#ifndef FUND_H
#define FUND_H

#include <iostream>
#include <string>

using namespace std;

class Fund
{
protected:

    int userId;
    int date;
    string item;
    double amount;

public:
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
};

#endif
