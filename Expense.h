#ifndef EXPENSE_H
#define EXPENSE_H

#include <iostream>
#include <string>

#include "Fund.h"

using namespace std;

class Expense : public Fund
{
    int expenseId;

public:
    int getExpenseId();
    void setExpenseId(int expenseId);

};

#endif
