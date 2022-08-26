#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>

using namespace std;

class Expense
{
    int expenseId;
    int userId;
    int date;
    string item;
    double amount;

public:
    int getExpenseId();
    int getUserId();
    int getDate();
    string getItem();
    double getAmount();

    void setExpenseId(int expenseId);
    void setUserId(int userId);
    void setDate(int date);
    void setItem(string item);
    void setAmount(double amount);
};

#endif
